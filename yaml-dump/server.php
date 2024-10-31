<?php
require __DIR__ . '/vendor/autoload.php';

use Ratchet\MessageComponentInterface;
use Ratchet\ConnectionInterface;

class TerminalWebSocket implements MessageComponentInterface {
    protected $clients;

    public function __construct() {
        $this->clients = new \SplObjectStorage;
    }

    public function onOpen(ConnectionInterface $conn) {
        $this->clients->attach($conn);
        echo "New connection! ({$conn->resourceId})\n";
    }

    public function onMessage(ConnectionInterface $from, $msg) {
        parse_str($from->httpRequest->getUri()->getQuery(), $queryParams);
        $pod_id = intval($queryParams['pod_id']);

        $process = proc_open(
            "kubectl exec -it pod-$pod_id -- /bin/bash",
            [
                ["pipe", "r"], // stdin
                ["pipe", "w"], // stdout
                ["pipe", "w"]  // stderr
            ],
            $pipes
        );

        if (is_resource($process)) {
            fwrite($pipes[0], $msg);
            fclose($pipes[0]);

            while ($output = fgets($pipes[1])) {
                $from->send($output);
            }

            fclose($pipes[1]);
            proc_close($process);
        }
    }

    public function onClose(ConnectionInterface $conn) {
        $this->clients->detach($conn);
        echo "Connection {$conn->resourceId} has disconnected\n";
    }

    public function onError(ConnectionInterface $conn, \Exception $e) {
        echo "An error has occurred: {$e->getMessage()}\n";
        $conn->close();
    }
}

use Ratchet\App;

$app = new App('localhost', 8080, '0.0.0.0');
$app->route('/terminal', new TerminalWebSocket, ['*']);
$app->run();

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

// Gestionnaire de signal SIGTERM pour le fils
void gestionnaire_sigterm(int sig) {
  printf("Le fils a reçu SIGTERM. Terminaison en cours...\n");
  exit(0); 
}

int main() {
  pid_t pid_fils = fork();

  if (pid_fils == -1) {
    perror("Erreur lors du fork");
    exit(1);
  } else if (pid_fils == 0) {
    // Code du processus fils

    // Installer le gestionnaire de signal SIGTERM
    signal(SIGTERM, gestionnaire_sigterm); 

    int secondes = 0;
    while (1) {
      printf("Secondes écoulées : %d\n", secondes++);
      sleep(1); 
    }
  } else {
    // Code du processus père
    sleep(10); 

    // Envoyer SIGTERM au fils 
    if (kill(pid_fils, SIGTERM) == -1) {
      perror("Erreur lors de l'envoi du signal SIGTERM");
    } else {
      printf("Processus fils arrêté après 10 secondes.\n");
    }

    // Attendre la fin du fils
    wait(NULL);
  }

  return 0;
}

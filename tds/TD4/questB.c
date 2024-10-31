#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void  getPID(void* arg) {
    printf("PID: %d, Thread ID: %p\n", getpid(), pthread_self());
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        perror("erreur");
        return 1;
    }

    int nb = atoi(argv[1]);
    pthread_t threads[nb];

    for (int i = 0; i < nb; i++) {
        pthread_create(&threads[i], NULL,&getPID, NULL);
    }

    for (int i = 0; i < nb; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
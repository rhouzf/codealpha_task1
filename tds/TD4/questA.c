#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* helloworld(void* arg) {
    printf("Hello World!\n");
    return NULL;
}

int main(int argc, char* argv[]) {
   int i,nb=atoi(argv[1]);
    pthread_t threads[nb];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_threads>\n", argv[0]);
        return 1;
    }

   

    for (i = 0; i < nb; i++) {
        pthread_create(&threads[i], NULL, helloworld, NULL);
    }

    for (i = 0; i < nb; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
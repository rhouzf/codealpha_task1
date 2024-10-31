#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> // Pour getpid()

void* printHelloWorld(void *arg) {
    
    printf("Hello World! It's me, thread \n");
    printf("My PID is %d\n", getpid());
    printf("pthread_self() returns: %p\n", (int *)pthread_self());
    
}

int main(int argc, char* argv[]) {
   if (argc != 2) {
      perror("erreur");
      exit(1);
   }

   int num_threads = atoi(argv[1]);
   pthread_t *threads = malloc(num_threads * sizeof(pthread_t));

   for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, printHelloWorld, *arg);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    free(threads);
    return 0;
}

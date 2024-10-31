#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* printHelloWorld(void* threadid) {
    long tid;
    tid = (long)threadid;
    printf("Hello World! It's me, thread #%ld!\n", tid);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <number_of_threads>\n", argv[0]);
        return 1;
    }

    int num_threads = atoi(argv[1]);
    pthread_t threads[num_threads];
    int rc;
    long t;

    for(t=0; t<num_threads; t++){
        printf("In main: creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, printHelloWorld, (void *)t);
        if (rc){
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    /* Wait for all threads to complete */
    for(t=0; t<num_threads; t++) {
        pthread_join(threads[t], NULL);
    }

    /* Exit main thread */
    pthread_exit(NULL);
}


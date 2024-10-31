#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
	pid_t pid;
	int i;
	printf("Bonjour à tous\n");
	pid = fork();
	printf("je suis le processus : %d, pid : %d\n", getpid(), pid);
	sleep(1);
	for(i=0; i<3; i++) {
		printf("proc : %d i : %d\n", getpid(), i);
		sleep(1);
	}
	if (pid == 0) {
		printf("je suis le fils et je termine\n");
	} else {
		printf("je suis le père et je termine\n");
	}
}

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
	pid_t pid;
	pid = fork();
	switch(pid) {
		case -1 : perror("erreur :");break;
		case 0 : printf("processus fils : %d %d\n", getpid(), getppid());break;
		default :
			 printf("processus père : %d\n", getpid());
	}
	printf("fin : %d \n", getpid());}





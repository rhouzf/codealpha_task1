#include<stdlib.h>
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>
void main () {
	pid_t pid;
	int status;
	pid=fork();
	if (pid == 0) {
		execl("/bin/ls", "ls", "-l", NULL); 
	}
	wait(&status);
	if(status) { printf("commande mal deroule  ");
		exit(1);}
		
	else {printf("Fils terminé !\n");
	exit(0);}
}

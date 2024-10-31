#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	    pid_t pid;
	        int status;

		    pid = fork();
		        if (pid == 0) {
				        // Nous sommes dans le processus fils
					         exit(3);  // Le processus fils se termine avec la valeur 3
					             } else {
					                     // Nous sommes dans le processus parent
				                             wait(&status);  // Attend la fin du processus fils
					                                     if (WIFEXITED(status)) {
					                                                 printf("Le processus fils s'est terminé avec la valeur %d\n", WEXITSTATUS(status));
					 }return 0 }                                           

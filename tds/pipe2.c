#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>
int main(int argc, char *argv[]) {
	    if (argc != 3) {
		            fprintf(stderr, "Usage: %s utilisateur hiérarchie\n", argv[0]);
			            return 1;
				        }

	        char *utilisateur = argv[1];
		    char *g = argv[2];
		        int p[2];
			    pipe(p);

			        if (fork() == 0) {
					        dup2(p[1], STDOUT_FILENO);
						        close(p[0]);
							        close(p[1]);
								        execlp("find", "find", g, "-type", "f", "-user", utilisateur, NULL);
									    }

				    close(p[1]);

				        if (fork() == 0) {
						        dup2(p[0], STDIN_FILENO);
							        close(p[0]);
								        execlp("wc", "wc", "-l", NULL);
									    }

					    close(p[0]);

					        wait(NULL);
						    wait(NULL);

						        return 0;
}


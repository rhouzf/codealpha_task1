#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	    int p1[2], p2[2];
	        pipe(p1);
		    pipe(p2);

		        if (fork() == 0) {
				        dup2(p2[1], STDOUT_FILENO);
					        close(p2[0]);
						        close(p2[1]);
							        execlp("grep", "grep", "votre_motif", NULL);
								    }

			    if (fork() == 0) {
				            dup2(p2[0], STDIN_FILENO);
					            dup2(p1[1], STDOUT_FILENO);
						            close(p2[0]);
							            close(p2[1]);
								            close(p1[0]);
									            close(p1[1]);
										            execlp("ls", "ls", NULL);
											        }

			        dup2(p1[0], STDIN_FILENO);
				    close(p1[0]);
				        close(p1[1]);
					    execlp("wc", "wc", NULL);

					        return 0;
}


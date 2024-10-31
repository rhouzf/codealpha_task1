#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/fcntl.h>
#include<unistd.h>
#include<sys/wait.h>


// Fonction pour lire un fichier et retourner une valeur entière
int read_file(const char *filename) {
     int result;
         FILE *file = fopen(filename, "r");
	 if (file != NULL) {
                     fscanf(file, "%d", &result);
		     fclose(file);
	 }
                                     return result;
}
                                     int main(int argc,char** argv)
                                     {
                                     	int pid,status;

                                     		if (argc != 2) {
                                     				printf("Usage : %s  file \n", argv[0]);
                                     						exit(1);
                                     							}
                                     								pid=fork();
                                     									switch(pid)                                     										{
                                    										                              													case -1 :                                     																	perror("Couldn't creat child process \n");
	exit(2);
                                     																									break;
                                     																												case 0 :
                                     																																exit(read_file(argv[1]));
                                     																																				break;
                                     																																							default :
                                     																																											wait(&status);
                                     																																															printf("son ended with code %d\n",status);
                                     																																																			break;
                                     																																																				}

                                     																																																					return 0;
                                     																																																					}


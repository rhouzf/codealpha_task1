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
   int i,pid,status;
   if(argc<2){
                printf("Usage : %s  files... \n", argv[0]);
                exit(1);}
   for(i=1;i<argc;i++){pid=fork();
                switch(pid)	{                                     								                       case -1 :  perror("Couldn't creat child process \n");
				exit(2);			
				break;
			case 0 : exit(read_file(argv[i]));
break;			default :wait(&status);
			if(status!=0)
				exit(2);													break;}									}											return 0;                                     					
													}

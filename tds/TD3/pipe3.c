

#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
    int tube[2];
    pipe(tube);
    switch(fork()){
      case -1:printf("Erreur");
      case 0:
        close(tube[0]);   
        close(1);        
        dup(tube[1],close(tube[1]);
        /dup(1,tube)/

        if(pipe(tube)==-1)
        printf("erreur creation pipe");
        switch(fork()){     
          case -1:printf("Erreur");
          case 0:  
            close(tube[0]);
            close(1);
            dup(tube[1],close(tube[1]);
            execlp("ls","ls","-Ral",argv[1],NULL);
            exit(2);
          default:

          close(0);
          close(tube[1]);
          dup(tube[0],close(tube[0]);
          execlp("grep","grep",argv[2],NULL);
          exit(3);
      Default:&
       close(tube[1]);close(0);
       dup(tube[0],close(tube[0]);
       execlp("wc","wc","l",NULL);
       exit(4);
     exit(0);}
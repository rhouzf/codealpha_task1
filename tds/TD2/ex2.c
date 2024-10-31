#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <sys/wait.h>



int afficher(char *nomExterne){

char buffer[BUFSIZ];
int desc;
int nbLus;

if((desc=open(nomExterne,O_RDONLY))==-1)
return -1;
while((nbLus=read(desc,buffer,BUFSIZ))>0)
write(1,buffer,nbLus);
close (desc);
return 0;
}


int main(int argv,char* argc[]) {
pid_t pid;
int i,status;
for(i=1;i<argv;i++){
   pid = fork();
  if(pid==0){
      printf("processus fils : %d %d\n", getpid(), getppid());
               if(argv<2){
                   perror("Erreur nb argument");
                    exit(1);}

               if((afficher(argc[i]))==-1){
                 printf("Erreur affichage %s \n",argc[i]);
                 exit(3);
                }
     }
   else if(pid<0){
           perror("erreur :");
      }
   else {
        printf("processus père : %d\n", getpid());
        if(  wait(&status)!=0){
                   exit(4);}
  
   }

}
printf("fin : %d \n", getpid());
exit(0);
}




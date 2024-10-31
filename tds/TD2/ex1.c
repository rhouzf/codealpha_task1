#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int afficher(char *nomexter){
int desc,nbrlus;
char buffer[10];
 if((desc=open(nomexter,O_RDWR))==-1)
    perror("ouverture non possible :");

while((nbrlus=read(desc,buffer,10*sizeof(char)))>0)
if(write(1,buffer,nbrlus)==-1) {
    return -1;} 
close(desc);
return 0;
}



int main(int argc,char* argv[]) {
/*pid_t pid;
pid = fork();
switch(pid) {
case -1 : perror("erreur :");break;
case 0 : printf("processus fils : %d %d\n", getpid(), getppid());
int i;
if(<2){
perror("Erreur nb argument");
exit(1);}

 if((afficher(v[1]))==-1){
printf("Erreur affichage %s \n",v[i]);
exit(3);}

exit(0); break;
default :
printf("processus père : %d\n", getpid());
}
printf("fin : %d \n", getpid());
}*/

pid_t pid;
pid=fork();
if( argc<2){
    printf("usage:%s file",argv[0]);
}

 switch(pid) {
 case -1 : perror("erreur :");break;
case 0 : printf("processus fils : %d %d\n", getpid(), getppid());
        if(afficher(argv[1])==-1){
        printf("erreur affichage:%s file",argv[1]);
          }break;
            
default : 
printf("processus père : %d\n", getpid());
 }
 printf("fin : %d \n", getpid());
   
}


                  
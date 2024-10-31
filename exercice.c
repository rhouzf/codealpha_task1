#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
void traittsignal(int num);
int main(int argc , char *argv[]){
    int NbSig;
    struct sigaction *act;
    
    for (NbSig = 1; NbSig < NSIG; NbSig++) {
    //    signal(NbSig, traittsignal) ; 
       act=(struct sigaction *)malloc(sizeof(struct sigaction));
       act->sa_handler = traittsignal;
       act->sa_flags = SA_NODEFER;
       sigaction (NbSig,act,NULL);
   }
    while(1){
        sleep(5);
   }// attendre les signaux 
    exit (0);
}
void traittsignal(int num ){
        printf("signal reçue %d \n",num);
        signal(num,traittsignal);
    
}
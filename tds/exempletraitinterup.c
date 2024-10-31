
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<signal.h>


int cpt=0;
void handler(int sig){
	
        
	printf("SIGINT reçu ");
        cpt++;        
}

int main(){
	struct sigaction nvt,old;
	memset(&nvt,0,sizeof(nvt));
	nvt.sa_handler=&handler;
	sigaction(SIGINT,&nvt,&old);
	while(cpt<2){
		if(cpt==2) exit(0);}
	pause();
	printf("ceci n'est jamis affiche");
}

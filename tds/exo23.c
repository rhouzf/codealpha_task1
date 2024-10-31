#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

int main (int argc ,char* argv[]){
	int pid,cr;
	switch(pid=fork()){
			case -1: perror("echec creation");
				 	        exit(2);
				 	case 0://printf("\ncase 0 switch 1 execl gcc %s\n",argv[1]);
					       //		if(num==creat(fichier,0777){
					       //					printf("erreur creation fichier==-1);
					       //								exit(3);}
					       //										dup2(2,num);
					       //											        execlp("gcc","gcc",argv[1],NULL);
					       //											         	        printf("erreur sur la commande gcc");
					       //											         	        		exit(4);
					       //											         	        			default:wait(&cr);
					       //											         	        					 //printf("\ncase default  switch 1 crgcc = %d\n",crgcc);
					       //											         	        					 		if(cr){
					       //											         	        					 					switch(pid=fork()){
					       //											         	        					 									case -1: perror("echec creation");
					       //											         	        					 														exit(5);
					       //											         	        					 																		case 0: 
					       //											         	        					 																						      //printf("\ncase 0 switch 2 crgcc=%d crpg=%d,exelp pg \n",crgcc,crpg);
					       //											         	        					 																						      				      execlp("pg","pg",argv[1],NULL);
					       //											         	        					 																						      				      				      printf("erreur pg");
					       //											         	        					 																						      				      				      				      exit(6);
					       //											         	        					 																						      				      				      				      				default:wait(&cr);
					       //											         	        					 																						      				      				      				      								      execlp("vi","vi",argv[1],NULL);
					       //											         	        					 																						      				      				      				     

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <unistd.h> 
#include <stdlib.h>
void main (int argc,char *argv[3]){
                       int desc;
		       char c;
		        if (argc != 2) {
		         printf("Usage : %s file\n", argv[0]);
		         exit(1);
		          }
		           
		            if ((desc = open(argv[1], O_CREAT|O_WRONLY|O_TRUNC, 0600)) == -1) {
		             perror("Ouverture impossible :");
		             exit(2);
		              }
		               while(scanf("%c", &c) != EOF) { // EOF renvoyé si <ctrl>D correspond à -1
		               write(desc, &c, 1);
		                } 
		                 close(desc);
		                 }

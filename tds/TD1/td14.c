#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void main(int argc,char** argv)
{ int desc,descr,nblus,i;
	  char buf[1000];
	  	
	  	if(argc<4){perror("erreur 1\n");
					exit(1);
							}
			if((descr=open(argv[argc-1],O_RDWR))==-1){
						perror("erreur 2\n");
								exit(2);
										}
				dup2(descr,1);
					close(descr);
						for(i=1;i<argc-1;i++){
									if((desc=open(argv[i],O_RDONLY))==-1){
													perror("open file \n");
																	}
											while((nblus=read(desc,buf,sizeof(buf)))>0){
														write(1,buf,nblus);	
																}
													close(desc);}}

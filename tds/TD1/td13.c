#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <unistd.h>

void main(int argc,char** argv)
{ int desc,nblus,i;
	  char buf[1000];
	  	if (argc < 2) {
					perror("error \n");
							exit(1);
								}
			for(i=1;i<argc;i++){
						if((desc=open(argv[i],O_RDONLY))==-1){
									perror("open file \n");
											exit(2);
													}
							while((nblus=read(desc,buf,sizeof(buf)))>0){
									write(1,buf,nblus);
										printf("\n");	
											close(desc);
												}

								}
}























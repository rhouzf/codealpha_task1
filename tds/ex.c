#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<fcntl.h>

int main(){
	int code;
	if(fork()==0){
		 code = execl("/bin/ls", "ls", "-a", 0);
		if (code!=0){printf("error");}
	}else{ 
		wait(NULL);
	}
	exit(0);
}
	



#include<sys/times.h>
#include<stdio.h>
void attributs(){
	printf("lePID:%d , le ppid:%d \n",getpid(),getppid());
}
int main(){
	printf("je suis le pere");
	attributs();
	int p1;
	if(p1=fork()==0){
		printf("je suis le fils");
		attributs();
	}
}


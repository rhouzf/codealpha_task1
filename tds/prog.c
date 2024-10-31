::nclude<sys/signal.h>
void attributs{
	printf("le PID:%d",getpid());
}
int main{
	int p1,p2;
	if(p1=fork()=0){
		attributs();
		if(p2=fork()=0){
			attributs();}
	}
}


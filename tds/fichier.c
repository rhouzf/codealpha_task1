#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>


void main()
{
	execl("/bin/ls", "ls", "-l", (char *) 0);
	/* avec execlp, le premier argument peut n’être
	 * que ls et non /bin/ls */
	printf("pas d’impression\n");
}

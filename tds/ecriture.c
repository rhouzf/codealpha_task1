#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <stdlib.h>
void  main(int argc, char **argv)
{
	 int desc, nb_lu;
	  char tab[8];
	   if (argc != 2) {
		    printf("Usage : %s file\n", argv[0]);
		    exit(1);
		     }
	    
	    if ((desc = open(argv[1], O_RDONLY)) == -1) {
		     perror("Ouverture impossible :");
		     exit(2);
		      }
	     while((nb_lu = read(desc, tab, 7*sizeof(char))) > 0) { 
		      tab[nb_lu]='\0';
		      printf("nb_lu : %d %s\n", nb_lu, tab);
		       } 
	      close(desc);
}

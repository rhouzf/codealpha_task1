#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <unistd.h>


void afficher(char* src){
		int desc;int nblus;
			char buf[1000];
				if((desc=open(src,O_RDONLY))==-1){
						perror("open file \n");
							exit(1);
								}
					while((nblus=read(desc,buf,sizeof(buf)))>0){
							write(1,buf,nblus);
								}
						close(desc);
}


void main(int argc,char** argv)
{
		
		if (argc < 2) {
					printf("Usage : %s fileSrc fileDst\n", argv[0]);
							exit(1);
								}

			afficher(argv[1]);
}
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void copier(char* src, char* dst) {
    int desc_src, desc_dst;
    int nblus;
    char buf[1000];

    // Ouvrir le fichier source en lecture seule
    if ((desc_src = open(src, O_RDONLY)) == -1) {
        perror("Erreur lors de l'ouverture du fichier source");
        exit(1);
    }

    // Ouvrir/créer le fichier de destination en écriture
    if ((desc_dst = open(dst, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1) {
        perror("Erreur lors de l'ouverture du fichier de destination");
        close(desc_src);
        exit(1);
    }

    // Lire du fichier source et écrire dans le fichier de destination
    while ((nblus = read(desc_src, buf, sizeof(buf))) > 0) {
        if (write(desc_dst, buf, nblus) != nblus) {
            perror("Erreur lors de l'écriture dans le fichier de destination");
            close(desc_src);
            close(desc_dst);
            exit(1);
        }
    }

    if (nblus == -1) {
        perror("Erreur lors de la lecture du fichier source");
    }

    // Fermer les descripteurs de fichier
    close(desc_src);
    close(desc_dst);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage : %s fileSrc fileDst\n", argv[0]);
        exit(1);
    }

    copier(argv[1], argv[2]);
    return 0;
}

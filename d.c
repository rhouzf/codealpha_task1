#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h> 
#define BUF_SIZE 1000

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Utilisation : %s <source> <destination>\n", argv[0]);
    exit(1);
  }

  int tube[2];
  pid_t pid;
  int desc_src, desc_dest, nblu;
  char buf[BUF_SIZE];

  if (pipe(tube) == -1) {
    perror("Erreur lors de la création du tube");
    exit(1);
  }

  pid = fork();
  if (pid == -1) {
    perror("Erreur lors du fork");
    exit(1);
  } else if (pid == 0) { 
    // Processus fils
    close(tube[0]); // Ferme la partie lecture du tube

    desc_src = open(argv[1], O_RDONLY);
    if (desc_src == -1) {
      perror("Erreur lors de l'ouverture du fichier source");
      exit(1);
    }

    while ((nblu = read(desc_src, buf, BUF_SIZE)) > 0) {
      if (write(tube[1], buf, nblu) != nblu) {
        perror("Erreur lors de l'écriture dans le tube");
        exit(1);
      }
    }

    if (nblu == -1) {
      perror("Erreur lors de la lecture du fichier source");
      exit(1);
    }

    close(desc_src);
    close(tube[1]); 
  } else { 
    // Processus père
    close(tube[1]); // Ferme la partie écriture du tube

    desc_dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (desc_dest == -1) {
      perror("Erreur lors de l'ouverture du fichier destination");
      exit(1);
    }

    while ((nblu = read(tube[0], buf, BUF_SIZE)) > 0) {
      if (write(desc_dest, buf, nblu) != nblu) {
        perror("Erreur lors de l'écriture dans le fichier destination");
        exit(1);
      }
    }

    if (nblu == -1) {
      perror("Erreur lors de la lecture du tube");
      exit(1);
    }

    close(desc_dest);
    close(tube[0]); 

    wait(NULL); // Attend la fin du fils
  }

  return 0;
}

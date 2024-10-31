#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() {
  int tube[2];
  pid_t pid;
  char msg[100];

  // Création du tube
  if (pipe(tube) == -1) {
    perror("Erreur lors de la création du tube");
    exit(EXIT_FAILURE);
  }

  pid = fork();

  if (pid == -1) {
    perror("Erreur lors de la création du processus fils");
    exit(EXIT_FAILURE);
  } 
  
  if (pid == 0) { 
    // Processus fils
    close(tube[0]); // Fermer la partie lecture du tu


      scanf(" %[^\n]", msg); 

    write(tube[1], msg, sizeof(msg) ); 
    close(tube[1]); 

  } else { 
    // Processus parent
    close(tube[1]); // Fermer la partie écriture du tube

    read(tube[0], msg, 100);
    close(tube[0]); 

    for (int i = 0; msg[i]; i++) {
      msg[i] = tolower(msg[i]);
    }

    printf("Message traduit : %s\n", msg); 

    wait(NULL); // Attendre la fin du fils
  }

  return 0;
}

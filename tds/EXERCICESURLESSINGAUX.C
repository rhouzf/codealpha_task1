#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

// Variable pour stocker le PID du fils
pid_t pid;int cpt;

// Fonction pour le gestionnaire de signal SIGUSR1 du fils
void sigusr1_handler(int signum) {
  int cpt=0;
}

int main() {
   
    // Enregistrement du gestionnaire de signal SIGUSR1 pour le fils

    // Creation du processus fils
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // Processus fils
        // Le fils attend le signal SIGUSR1 du pere
    signal(SIGUSR1, sigusr1_handler);
       while(cpt<10){
        sleep(1);
        cpt++;
       }
        // Si le fils n'a pas recu le signal SIGUSR1 dans les 10 secondes, il envoie un signal SIGTERM au pere
        printf("Le fils envoie SIGTERM au pere.\n");
        kill(getppid(), SIGTERM);
        exit(EXIT_SUCCESS);
    } else { // Processus pere 
    int n=1;
        // Boucle infinie du pere
        while (1) {
            printf("Le pere continue a s'executer.\n");
            //Sn++;printf("%d)",n);
            sleep(1);
           /* if(n==10){n=0;printf("Le pere envoie SIGUSR1 au fils.\n");
            kill(pid, SIGUSR1);}*/
        }
    }

    return 0;
}
/*exo:
Réalisez le programme veille qui effectue les opérations suivantes:

§  le programme se duplique en créant un fils;

§  le père exécute une boucle infinie;

§  si toutes les (au plus) 10 secondes, le fils ne reçoit pas le signal SIGUSR1, il stoppe l'exécution du père.*/
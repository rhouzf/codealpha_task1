#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int num, pid, cr;
    char* fichier; // Nom du fichier de sortie

    if (argc != 2) {
        printf("Erreur: usage %s <fichier_source>\n", argv[0]);
        exit(1);
    }

    switch (pid = fork()) {
        case -1:
            perror("Échec de la création du processus");
            exit(2);

        case 0:
            // Processus fils
            num = creat(fichier, 0777);
            if (num == -1) {
                printf("Erreur: création du fichier échouée\n");
                exit(3);
            }
            dup2(num, 2); // Rediriger la sortie d'erreur vers le fichier
            close(num);
            execlp("gcc", "gcc", argv[1], NULL);
            printf("Erreur: échec de la commande gcc\n");
            exit(4);

        default:
            // Processus père
            wait(&cr);
            if (cr) {
                switch (pid = fork()) {
                    case -1:
                        perror("Échec de la création du processus");
                        exit(5);

                    case 0:
                        // Processus fils
                        execlp("pg", "pg", argv[1], NULL);
                        printf("Erreur: échec de la commande pg\n");
                        exit(6);

                    default:!
                        // Processus père
                        wait(&cr);
                        execlp("vi", "vi", argv[1], NULL);
                        printf("Erreur: échec de la commande vi\n");
                        exit(7);
                }
            } else {
                execlp("./a.out", "a.out", NULL);
                printf("Erreur: échec de l'exécution de a.out\n");
                exit(8);
            }

            exit(9);
    }
}
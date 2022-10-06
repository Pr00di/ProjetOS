#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int pid;

void sigint_handler()
{
    kill(pid, SIGUSR1);
}

int main(int argc, char *argv[])
{
    int status;
    if (argc < 2)
    {
        printf("[MERE]\tMauvais configuration , fin du programme !\n");
        exit(1);
    }
    printf("[MERE]\tTimer configurer à %s secondes !\n", argv[1]);
    pid = fork();
    if (pid == 0)
    {
        strcpy(argv[0], "F");
        printf("[MERE]\tLancement de la fille \n");
        execv("../bin/F", argv);
    }
    signal(SIGINT, sigint_handler);
    printf("[MERE]\tJ'attend la fin de ma tache fille ... \n");
    wait(&status);
    printf("[MERE]\tStatus de sortie de ma fille : %d\n", status >> 8);
    exit(0);
}

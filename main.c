#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int pid1, pid2;

void sigint_handler1()
{
    kill(pid1, SIGUSR1);
    kill(pid2, SIGUSR1);
}


int main(int argc, char *argv[])
{

    
//afficher heure en continu

    pid1 = fork();
    pid2 = fork();
    
    
     if (pid1 == 0 && pid2 != 0)
    {
        strcpy(argv[0], "FPChrono");
        printf("[MAIN]Lancement de FPChrono \n");
        execv("../bin/FPChrono", argv);
    }
    
    else{
	    if (pid1 == 0)
	    {
		strcpy(argv[0], "FPAlarm");
		printf("[MAIN]Lancement de FPAlarm \n");
		execv("../bin/FPAlarm", argv);
	    }
	    
	    
	    if (pid2 == 0)
	    {
		strcpy(argv[0], "FPConf");
		printf("[MAIN]Lancement de FPConf \n");
		execv("../bin/FPConf", argv);
	    }
    }
   
    
    signal(SIGINT, sigint_handler1);
    while (wait(NULL) < 0) {
    } //attendre que tous les enfants meurent
    exit(0);
}

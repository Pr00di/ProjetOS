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
    
    //menu
    int stop = 0;
    do{
	    system ("clear");
	    int choix = 0;
	    printf("1 - Lancer le chrono \n");
	    printf("2 - Configurer le reveil \n");
	    printf("3 - Afficher l'heure \n");
	    printf("4 - Quitter \n");
	    printf("Choix : ");
	    scanf("%d",&choix);
	    
	    //fork
	    pid1 = fork();
	    pid2 = fork();
    
	    //choix 
	    switch(choix){
	    
	    case 1 :
	    	if (pid1 == 0 && pid2 != 0){
			strcpy(argv[0], "FPChrono");
			execv("../bin/FPChrono", argv);
	    		} break;
	    
	    case 2 :
		if (pid1 == 0){
			strcpy(argv[0], "FPAlarm");
			execv("../bin/FPAlarm", argv);
		    	} break;
		    
	    case 3 :    
		if (pid2 == 0){
			strcpy(argv[0], "FPAffHD");
			execv("../bin/FPAffHD", argv);
		    	} break;
		    	
	    case 4 :    
		stop = 1;
		break;
	    }
	   
	    signal(SIGINT, sigint_handler1);	
	    
	    //attendre que tous les enfants meurent
	    while (wait(NULL) < 0) {}
	    
    }while (stop == 0);
    
    exit(0);
}

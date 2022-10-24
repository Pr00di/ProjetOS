#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void printMenu(void);

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
	int choix;

	while(stop == 0)
	{
		printMenu();
        scanf("%d",&choix);
	  
	    //fork
	    pid1 = fork();
	    pid2 = fork();
    
		//choix 
	    switch(choix)
		{
	    
	    	case 1 :
	    		if (pid1 == 0 && pid2 != 0)
				{
					strcpy(argv[0], "FPChrono");
					execv("~/Documents/ProjetOS/ProjetOS-main/FPChrono", argv);
					execl("/usr/bin/xterm", "xterm", "./FPChrono", NULL);
	    		}
			break;
	    
	    	case 2 :
				if (pid1 == 0)
				{
					strcpy(argv[0], "FPAlarm");
					execv("~/Documents/ProjetOS/ProjetOS-main/FPAlarm", argv);
					execl("/usr/bin/xterm", "xterm", "./Alarm", NULL);
		    	} 
			break;
		    
	    	case 3 :    
				if (pid2 == 0)
				{
					strcpy(argv[0], "FPAffHD");
					execv("~/Documents/ProjetOS/ProjetOS-main/FPAffHD", argv);// changer l'adresse en fonction de la ou vous avez mit votre dossier
					execl("/usr/bin/xterm", "xterm", "./AffHD", NULL);// Il faut bien appeler l'executable du fichier FPAffHD.c AffHD sinon cela ne marchera pas
		    	}
			break;
		    	
	    	case 4 :    
				stop = 1;
			break;
		
			default :
				printf("Commande inconnue\n");
			break;
	    }
	   
	    signal(SIGINT, sigint_handler1);	
	    
	    //attendre que tous les enfants meurent
	    while (wait(NULL) < 0) {}
	    
    }
    
   return(0);
}

void printMenu(void)
{
	printf("\nMenu:\n");
	printf("1 - Lancer le chrono \n");
    printf("2 - Configurer le reveil \n");
    printf("3 - Afficher l'heure \n");
    printf("4 - Quitter \n");
    printf("Choix : ");

}

//Problème de double fenetre d'affichage pour l'alarme et pas de bip
//Probleme pour quitter le programme
//Probleme au niveau du choix si on on se trompe dans le choix pas possible de redemander au user de retaper un chiffre correct
//Probleme pour quitter l'horloge il faudrait implementer une touche de sortie (Genre appuyer sur Q pour quitter le mode horloge)

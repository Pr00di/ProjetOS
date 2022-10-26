#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(void)
{
    
    printf ("-----Bienvenue sur IClock-----\n");
    sleep(2);
    int stop = 0;
    
    do{	    
	    system ("clear");
	    int pid;
	    int stat;
	    char * argv[2];
	    int choix = 0;
	    
	    printf ("-----Menu IClock-----\n\n");
	    printf("1 - Lancer le chrono \n");
	    printf("2 - Configurer le reveil \n");
	    printf("3 - Afficher l'heure \n");
	    printf("4 - Quitter \n");
	    printf("Choix >  ");
	    scanf("%d",&choix);
	    
	    pid = fork();
	    
	    if (choix == 4){
	    	stop = 1;
	    	
	    }else {
	    
		    if (pid == 0){

			    //choix 
			    switch(choix){
			    
			    case 1 :
		    		argv[0] = "FPChrono";
				argv[2]= NULL;
				execv("./FPChrono", argv);
				execl("/usr/bin/xterm", "xterm", "./FPChrono", NULL);
		    		break;
			    
			    case 2 :
				argv[0] = "FPAlarm";
				argv[2]= NULL;
				execv("./FPAlarm", argv);
				execl("/usr/bin/xterm", "xterm", "./FPAlarm", NULL);
			    	break;
				    
			    case 3 :    
				argv[0] = "FPAffHD";
		    		argv[2]= NULL;
				execv("./FPAffHD", argv);
				execl("/usr/bin/xterm", "xterm", "./FPAffHD", NULL);
			    	break;
				
			    default :    
				printf("Commande Inconnu\n");
				break;
			    }
			    
		    }else{
		    
			wait(&stat);
	   	    }
   	    }
	  
    }while (stop == 0);
    
    return(0);
}

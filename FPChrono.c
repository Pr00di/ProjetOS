#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <time.h>

int main (void) {
	
	time_t start = time (NULL); 
	
	printf("appuyer sur une touche pour arrêter le chrono et afficher le temps\n"); 
	
   	getchar();
	
	printf("duree = %ds\n", (int) (time(NULL)-start)); 
	
	printf("Redirection en cours ... \n");
	sleep(3); 
	
    exit(0);
	
}



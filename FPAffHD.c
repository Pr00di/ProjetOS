#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <time.h>

int main (void)
{

 int i;
 time_t secondes;
 struct tm instant;
 
 for(;;) {
 time(&secondes);
 instant=*localtime(&secondes);
 printf("%d/%d ; %d:%d:%d\n", instant.tm_mday, instant.tm_mon+1, instant.tm_hour, instant.tm_min, instant.tm_sec);
 sleep(1); 
 system ("clear"); 
 }
 printf("Redirection en cours ... \n");
	sleep(3); 
   exit(0);

}



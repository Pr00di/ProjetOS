#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h> 
#include <time.h> 

void reveil(){
    printf(" BIP BIP BOP !!!! \n");
}

int main (void)
{
    time_t timestamp = time( NULL );
    struct tm * instant = localtime( & timestamp );
    int heure, minute;
    int jour, mois;
    printf("A quelle heure veux-tu te lever ? (format heure:minutes )\n");
    scanf("%d:%d", &heure, &minute);
    printf("%d\n", heure);
    printf("%d\n", minute);
    printf("%d\n",instant->tm_hour);
    printf("%d\n",instant->tm_min);
    printf ("A quelle date veux tu le programmer ? (format jours/mois ) \n"); 
    scanf("%d/%d", &jour, &mois);
    printf("%d\n", jour);
    printf("%d\n", mois);
    printf("%d\n",instant->tm_mday);
    printf("%d\n",instant->tm_mon);
    while(1){
        if((heure == instant->tm_hour) && (minute == instant->tm_min) && (jour == instant->tm_mday) && (mois == (instant->tm_mon+1))){
            break;
        }
        timestamp = time( NULL );
        instant = localtime( & timestamp );
        printf("%d/%d ; %d:%d:%d\n", instant->tm_mday, instant->tm_mon+1, instant->tm_hour, instant->tm_min, instant->tm_sec);
        fflush(stdout);
        sleep(1);
        system ("clear");
    }
    reveil();
    signal(SIGALRM, reveil);
    exit(0);
}



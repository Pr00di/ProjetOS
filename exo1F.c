#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int stop = 0;

void sigusr1_handler(int sig)
{
    printf("\t[FILLE]\tInterruption caught : SIGUSR1 with id %d\n", sig);
    stop = 1;
    return;
}

void sigint_handler()
{
    return;
}

int main(int argc, char const *argv[])
{
    signal(SIGINT, sigint_handler);
    signal(SIGUSR1, sigusr1_handler);
    printf("\t[FILLE]\tStart Looping\n");
    int timer = atoi(argv[1]);
    int i;
    for (i = timer; i > 0 && !stop; i--)
    {
        printf("\t[FILLE]\t%d\n", i);
        sleep(1);
    }
    if (!stop)
        printf("\t[FILLE]\tC'EST L'HEURE !!!\n");
    exit(i);
}

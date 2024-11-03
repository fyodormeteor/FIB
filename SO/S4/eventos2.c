#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

int seconds = 0;

void sigtreatment(int s)
{
    if (s == SIGALRM)
    {
        seconds++;
        alarm(1);
    }
    else if (s == SIGUSR1)
    {
        seconds = 0;
    }
    else if (s == SIGUSR2)
    {
        char buff[128];
        sprintf(buff, "Time: %d\n", seconds);
        write(1, buff, strlen(buff));
    }
}

int main(int argc, char* argv[])
{
    struct sigaction sa;
    sigset_t mask;

    // Block all signals except ALARM, INT, USR1, USR2
    sigfillset(&mask);
    sigdelset(&mask, SIGALRM);
    sigdelset(&mask, SIGINT);
    sigdelset(&mask, SIGUSR1);
    sigdelset(&mask, SIGUSR2);
    sigprocmask(SIG_BLOCK, &mask, NULL);

    sa.sa_handler = &sigtreatment;
    sa.sa_flags = SA_RESETHAND;
    sigfillset(&sa.sa_mask);
    sigaction(SIGALRM, &sa, NULL);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    alarm(1);
    while(1);
}
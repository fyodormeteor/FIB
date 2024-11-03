#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

int i = 0;

void error_y_exit (char *msg, int exit_status)
{
    perror (msg);
    exit (exit_status);
}

void treatment(int s)
{
    while(waitpid(-1, NULL, WNOHANG) > 0)
    {
        char buff[128];
        sprintf(buff, "ha muerto un hijo lol\n");
        write(1, buff, strlen(buff));
        i--;
    }
}

int main(int argc, char* argv[])
{
    struct sigaction sa;
    sigset_t mask;

    // Reprogram SIGCHILD
    sa.sa_handler = &treatment;
    sa.sa_flags = SA_RESTART;
    sigfillset(&sa.sa_mask);

    if (sigaction(SIGCHLD, &sa, NULL) < 0) error_y_exit("sigaction", 1);

    // Make 5 children
    int r = 1;
    while (r > 0 && i < 5)
    {
        int r = fork();
        if (r == 0)
        {
            alarm(5);
        }
        i++;
    }

    while (i > 0);

    char buff[128];
    sprintf(buff, "hla soy el padre he matado todos los hijos y ahora acaba mi programa\n");
    write(1, buff, strlen(buff));
    i--;
}


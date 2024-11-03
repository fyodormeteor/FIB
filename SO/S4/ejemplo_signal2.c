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
    int status;
    int pid;
    while((pid = waitpid(-1, &status, WNOHANG)) > 0)
    {
        if (WIFEXITED(status))
        {
            char buff[128];
            sprintf(buff, "ha muerto %d con status %d\n", pid, WEXITSTATUS(status));
            write(1, buff, strlen(buff));
        }
        else if (WIFSIGNALED(status))
        {
            char buff[128];
            sprintf(buff, "ha muerto %d por el signal %d\n", pid, WTERMSIG(status));
            write(1, buff, strlen(buff));
        }
        else
        {
            char buff[128];
            sprintf(buff, "ha muerto un hijo y no se porque\n");
            write(1, buff, strlen(buff));
        }
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

    int pids[5];
    
    // Make 5 children
    int r = 1;
    int ischild = 0;
    while (r > 0 && i < 5)
    {
        int r = fork();
        if (r == 0)
        {
            alarm(5);
            ischild = 1;
        }
        if (r > 0) pids[i] = r;
        i++;
    }

    if (ischild == 0)
    {
        for (int j = 0; j < 5; j++)
        {
            kill(pids[j], SIGUSR1);
        }
    }

    while (i > 0);

    char buff[128];
    sprintf(buff, "hla soy el padre he matado todos los hijos y ahora acaba mi programa\n");
    write(1, buff, strlen(buff));
    i--;
}


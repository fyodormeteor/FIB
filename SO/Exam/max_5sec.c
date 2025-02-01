#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>

void error_and_exit(char* err) {
    char buf[256];
    sprintf(buf, "%s\n", err);
    write(1, buf, strlen(buf));
    exit(EXIT_FAILURE);
}

void Usage() {
    char buf[256];
    sprintf(buf, "Usage: ./max_5sec pid [pid ... pid]\n");
    write(1, buf, strlen(buf));
    exit(EXIT_FAILURE);
}

int USR1RECEIVED = 0;

int executiontime = -5;

void ras (int s) {
    if (s == SIGUSR1) {
        USR1RECEIVED = 1;
        executiontime += alarm(0);
    }
}

int main(int argc, char* argv[]) {

    struct sigaction sa;
    sa.sa_handler = ras;
    sa.sa_flags = 0;
    sigfillset(&sa.sa_mask);

    if (sigaction(SIGALRM, &sa, NULL) == -1) error_and_exit("sigaction");
    if (sigaction(SIGUSR1, &sa, NULL) == -1) error_and_exit("sigaction");

    sigset_t mask;
    sigfillset(&mask);
    sigprocmask(SIG_BLOCK, &mask, NULL);
    sigdelset(&mask, SIGALRM);
    sigdelset(&mask, SIGUSR1);

    while (!USR1RECEIVED){
        executiontime+=5;
        
        int r = fork();
        if (r == -1) error_and_exit("fork");

        if (r == 0) {
            execvp("./nproc_time_max", argv);
            error_and_exit("execvp");
        }

        alarm(5);
        sigsuspend(&mask);

    }

    char buf[24];
    sprintf(buf, "Segundos: %d", executiontime);
    write(1, buf, strlen(buf));
}
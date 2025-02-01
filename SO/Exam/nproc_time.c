#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

void error_and_exit(char* err) {
    char buf[256];
    sprintf(buf, "%s\n", err);
    write(1, buf, strlen(buf));
    exit(EXIT_FAILURE);
}

void Usage() {
    char buf[256];
    sprintf(buf, "Usage: ./nproc_time pid [pid ... pid]\n");
    write(1, buf, strlen(buf));
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    if (argc < 2) Usage();

    for (int i = 1; i < argc; i++) {
        char* PID = argv[i];
        int r = fork();
        if (r == -1) error_and_exit("fork");
        else if (r == 0) {
            execlp("./proc_time", "proc_time", PID, (char*)0);
            error_and_exit("execlp");
        }
        else if (r > 0) {
            int status;
            if (waitpid(r, &status, 0) == -1) error_and_exit("waitpid");
            if (WIFEXITED(status) && WEXITSTATUS(status) == 255) {
                error_and_exit("Some pid doesnt exist");
            }
        }
    }
}
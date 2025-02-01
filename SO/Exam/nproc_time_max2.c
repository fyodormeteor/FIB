#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#include 

void error_and_exit(char* err) {
    char buf[256];
    sprintf(buf, "%s\n", err);
    write(1, buf, strlen(buf));
    exit(EXIT_FAILURE);
}

void Usage() {
    char buf[256];
    sprintf(buf, "Usage: ./nproc_time_max2 pid [pid ... pid]\n");
    write(1, buf, strlen(buf));
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    if (argc < 2) Usage();

    // Create pipe
    // no error control on mknod, in case pipe already exists
    // could be done by checking errno but i have no time
    mknod("pipe", S_IFIFO|S_IRUSR|S_IWUSR, 0);

    for (int i = 1; i < argc; i++) {
        char* PID = argv[i];
        int r = fork();
        if (r == -1) error_and_exit("fork");
        else if (r == 0) {
            close(1);
            open("pipe", O_WRONLY, 0);
            execlp("./proc_time", "proc_time", PID, (char*)0);
            error_and_exit("execlp");
        }
    }
    
    char c;
    int n;
    int time_current = 0;
    int time_max = 0;

    int fd = open("pipe", O_RDONLY, 0);

    while ((n = read(fd, &c, 1)) > 0) {
        if (c == '\n') {
            if (time_current > time_max) time_max = time_current;
            time_current = 0;
            continue;
        }

        time_current *= 10;
        time_current += c - '0';
    }
    if (n == -1) error_and_exit("read");

    char buf[64];
    sprintf(buf, "%d\n", time_max);
    write(1, buf, strlen(buf));
}


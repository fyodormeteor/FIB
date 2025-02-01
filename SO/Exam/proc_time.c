#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

void error_and_exit(char* err) {
    perror(err);
    exit(EXIT_FAILURE);
}

void Usage() {
    char buf[256];
    sprintf(buf, "Usage: ./proc_time pid\n");
    write(1, buf, strlen(buf));
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    if (argc != 2) Usage();
    
    char pathname[128];
    sprintf(pathname, "/proc/%s/stat", argv[1]);

    int fd = open(pathname, O_RDONLY);
    if (fd == -1) {
        if (errno == ENOENT) exit(255); // file doesnt exist
        else error_and_exit("open");
    }

    char c;
    int read_spaces = 0;
    while (read_spaces != 13) {
        if (read(fd, &c, 1) == -1) error_and_exit("read");
        if (c == ' ') read_spaces++;
    }

    int time1 = 0;
    if (read(fd, &c, 1) == -1) error_and_exit("read");
    while (c != ' ') {
        time1 *= 10;
        time1 += c - '0';
        if (read(fd, &c, 1) == -1) error_and_exit("read");
    }

    int time2 = 0;
    if (read(fd, &c, 1) == -1) error_and_exit("read");
    while (c != ' ') {
        time2 *= 10;
        time2 += c - '0';
        if (read(fd, &c, 1) == -1) error_and_exit("read");
    }

    if (close(fd) == -1) error_and_exit("close");

    char buf[64];
    sprintf(buf, "%d\n", time1+time2);
    write(1, buf, strlen(buf));
}
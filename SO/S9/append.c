#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    char buf[128];
    int fd = open("file", O_RDONLY);
    int fd2 = open("file", O_WRONLY);
    lseek (fd, 0, SEEK_SET);
    int size = lseek(fd2, 0, SEEK_END);
    while (size != 0)
    {
        read(fd,buf,1);
        write(fd2,buf,1);
        --size;               
    }
    close(fd);
    close(fd2);
}
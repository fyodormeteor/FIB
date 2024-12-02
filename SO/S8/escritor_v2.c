#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

void main(int argc, char *argv[])
{
	char buff[80];
	int fd;

	do
	{
		sprintf(buff, "Waiting for a reader\n");
		write(1, buff, strlen(buff));
	}
    while ((fd = open("pipe", O_WRONLY | O_NONBLOCK)) == -1 && errno == ENXIO);

	sprintf(buff, "Reader found\n");
	write(1, buff, strlen(buff));

	char c;
	while(read(0, &c, sizeof(char)) > 0)
	{
        write(fd, &c, sizeof(char));
	}
}
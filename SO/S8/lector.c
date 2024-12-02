#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void error_y_exit(char* msg,int error_status)
{
	perror(msg);
	error(error_status);
}

int main()
{
	int fd = open("pipe",O_RDONLY);
	if(fd == -1) error_y_exit("open",1);

    char c;
	while(read(fd, &c, 1) > 0)
    {
		write(1, &c, 1);
	}
	close(fd);
}
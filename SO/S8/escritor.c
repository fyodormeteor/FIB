#include <stdlib.h>
#include <stdio.h>
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
	int fd = open("pipe",O_WRONLY);
	if(fd == -1) error_y_exit("open",1);

    char c;
	while(read(0, &c, 1) > 0)
    {
		write(fd, &c, 1);	
	}
	close(fd);
}
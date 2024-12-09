#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void exit_and_error(char* c)
{
	perror(c);
	exit(1);
}

void Usage(void)
{
	char buff[120] = "Usage: ./invirtiendo_fichero [arg1]";
	write(1, buff, strlen(buff));
	exit(0);
}

int main(int argc, char *argv[])
{
	if (argc < 2) Usage();

	int fd1, fd2, start;
	if ((fd1 = open(argv[1], O_RDONLY)) < 0) exit_and_error("Error in open");
	if (lseek(fd1, -1, SEEK_END) < 0) exit_and_error("Error in lseek");

	char *input = argv[1];
	
	char buff[120];
	sprintf(buff, "%s.inv", input);
	write(1, buff, strlen(buff));

	if ((fd2 = creat(buff, 0600)) < 0) exit_and_error("Error in creat");
	
	char c;
	start = -2;
	
	while (read(fd1, &c, sizeof(char) > 0))
    {
		write(fd2, &c, sizeof(char));
		if (lseek(fd1, start, SEEK_END) < 0){
			return 0;	
		} 
		--start;
	}
}

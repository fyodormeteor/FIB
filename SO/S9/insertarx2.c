#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

void exit_and_error(char* c)
{
	perror(c);
	exit(1);
}

void Usage(void)
{
	char buff[120] = "Usage: ./insertarx2 [arg1]";
	write(1, buff, strlen(buff));
	exit(1);
}

int main(int argc, char *argv[])
{
	if (argc < 2) Usage();

	int pos = atoi(argv[2]);
	char c;
	int fd, start;
	char buff[120];

	if ((fd = open(argv[1], O_RDWR)) < 0) exit_and_error("Error in open");
	if (lseek(fd, 0, SEEK_END) < 0) exit_and_error("Error in lseek");

	lseek(fd, -1, SEEK_END);
	start = -2;
	while (read(fd, &c, sizeof(char)) > 0)
    {
		write(fd, &c, sizeof(char));

		if (lseek(fd, start, SEEK_END) < 0) {
			return 0;
		}
		--start;
		if (lseek(fd, 0, SEEK_CUR) == pos) {
			write(fd, "X", sizeof(char));
			return 0;
		}
	}
}

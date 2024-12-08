#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main() {
	char buf1[256];
	char buf2[256];
	int fd = open("salida.txt", O_RDWR);

	lseek(fd,-1,SEEK_END);
	read(fd,buf1,sizeof(char));
	lseek(fd,-1,SEEK_CUR);
	sprintf(buf2,"X");
	
	write(fd,buf2,sizeof(char));
	write(fd,buf1,sizeof(char));
}
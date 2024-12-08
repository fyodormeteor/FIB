#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
	char buf[256];
    // 000 110 000 000
	int f = creat("salida.txt",O_CREAT|O_TRUNC|0600);
	sprintf(buf,"ABCD");
	write(f,buf,strlen(buf));
}
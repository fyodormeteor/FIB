#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    int fd, num;
    read(0, &num, sizeof(int));

    // write the read number to check

    char buf[32];
    sprintf(buf, "%d", num);
    write(1, &buf, strlen(buf));
}
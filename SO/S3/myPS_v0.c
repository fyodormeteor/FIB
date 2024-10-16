#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void error_and_exit(char *msg,int exit_status)
{
    perror(msg);
    exit(exit_status);
}

void Usage() {
    char buffer[128];
    sprintf(buffer, "Usage: myPS username\nThis program executes a ps of the processes of the user it receives as a parameter\n");
    write(1, buffer, strlen(buffer));
}

int main(int argc, char* argv[]) {
    if (argc < 2)
    {
        Usage();
        return 0;
    }
    
    int pid = fork();
    char* usern = argv[1];
    char buffer[128];

    switch(pid) {
        // Child
        case 0:

        sprintf(buffer, "Child PID: %i\nUsername: %s\n", getpid(), usern);
        write(1, buffer, strlen(buffer));

        break;

        // Error
        case -1:

        error_and_exit("Error in fork",1);

        break;

        // Parent
        default:

        sprintf(buffer, "Parent PID: %i\n", getpid());
        write(1, buffer, strlen(buffer));

        break;
    }

    while (1)
    {

    }

    return 0;
}
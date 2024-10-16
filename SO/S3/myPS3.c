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

/* Execute the command ps –u username using the system call execlp */
/* Returns: the error code in case it couldn’t be mutated */
void mute_to_PS(char *username) {
    execlp("ps", "ps", "-u", username, (char*) 0);
    error_and_exit("The ps mutation has failed", 1);
}

int main(int argc, char* argv[]) {
    if (argc < 2)
    {
        Usage();
        return 0;
    }
    
    char buffer[128];
    sprintf(buffer, "Parent PID: %i\n", getpid());
    write(1, buffer, strlen(buffer));

    for (int i = 1; i < argc; i++){
        int pid = fork();
        char* usern = argv[i];
        
        if (pid == 0) {
            mute_to_PS(usern);
        }
        if (pid == -1) error_and_exit("Error in fork",1);
    }

    while (waitpid(-1,NULL,0)>0); // wait for all the children.

    char c;
    read(0, &c, sizeof(char));

    return 0;
}
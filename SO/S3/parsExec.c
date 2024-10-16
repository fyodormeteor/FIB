#include <unistd.h>
#include <wait.h>
#include <stdio.h>
#include <stdlib.h>


void error_exit(char *msg, int exit_status) {
    perror (msg);
    exit(exit_status);
}
int fork_check_error() {
    int pid;
    if ((pid = fork()) < -1) error_exit("Error in fork", 1);
    return pid;
}

int main(int argc, char *argv[]) {
    int pid;
    pid = fork_check_error();
    if (pid == 0) {
        execlp("./listaParametros", "listaParametros", "a", "b", (char*)NULL);
        error_exit("Failed to mutate to listaparametros", 1);
    }
    pid = fork_check_error();
    if (pid == 0) {
        execlp("./listaParametros", "listaParametros", (char*)NULL);
        error_exit("Failed to mutate to listaparametros", 1);
    }
    pid = fork_check_error();
    if (pid == 0) {
        execlp("./listaParametros", "listaParametros", "25", "4", (char*)NULL);
        error_exit("Failed to mutate to listaparametros", 1);
    }
    pid = fork_check_error();
    if (pid == 0) {
        execlp("./listaParametros", "listaParametros", "1024", "hola", "adios", (char*)NULL);
        error_exit("Failed to mutate to listaparametros", 1);
    }
    while (waitpid(-1,NULL,0) > 0);
    return 0;
}
#include "my_functions.h"

void Usage()
{
	char buffer[128];
	sprintf(buffer, "Usage:suma arg1 [arg2..argn]\nThis program writes in the standard output the sum of the arguments\n");
	write(1, buffer, strlen(buffer));
}


int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        Usage();
        return 0;   
    }
    
    int suma = 0;

    for (int i = 1; i < argc; i++) {
        if (isNumber(argv[i]) == 1) {
            suma += mi_atoi(argv[i]);
        } else {
            char buffer[128];
            sprintf(buffer, "Error: %s is not a number.\n", argv[i]);
            write(1, buffer, strlen(buffer));
            return 0;
        }
    }

    char buffer[128];
    sprintf(buffer, "The addition is %i\n", suma);
    write(1, buffer, strlen(buffer));

    return 0;
}

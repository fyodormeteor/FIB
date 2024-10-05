#include "my_functions.h"

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++) {
        char buffer[128];

        if (isNumber(argv[i]) == 1) {
            sprintf(buffer, "%s is a number.\n", argv[i]);
        } else {
            sprintf(buffer, "%s is not a number.\n", argv[i]);
        }

        write(1, buffer, strlen(buffer));
    }

    return 0;
}

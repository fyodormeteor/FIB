#include <stdio.h>
#include <string.h>
#include <unistd.h>

void Usage()
{
	char buffer[128];
	sprintf(buffer, "Usage:words arg1 \nThis program writes in the standard output the number of words in the first argument\n");
	write(1, buffer, strlen(buffer));
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        Usage();
        return 0;
    }
    
    char* sen = argv[1];
    int last_char_is_separator = 1;
    int word_count = 0;

    while (*sen != '\0') {
        if (*sen == ' ' || *sen == '.' || *sen == ',' || *sen == '\n') {
            if (last_char_is_separator == 0) {
                word_count++;
            }
            last_char_is_separator = 1;
        } else last_char_is_separator = 0;

        sen++;
    }

    if (last_char_is_separator == 0) {
        word_count++;
    }

    char buffer[64];
    sprintf(buffer, "Words: %i\n", word_count);
    write(1, buffer, strlen(buffer));
}
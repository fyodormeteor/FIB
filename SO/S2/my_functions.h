#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 8

// Converts a char to int
unsigned int char2int(char c);

// Converts a string to a number int
int mi_atoi(char *s);

// Checks if string is a number
int isNumber(char *str);
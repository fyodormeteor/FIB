#include "my_functions.h"

#define MAX_SIZE 8

unsigned int char2int(char c)
{
    return c - '0';
}

int mi_atoi(char *s)
{
    int result = 0;
    int neg = 0;
    int cont = 1;

    if (*s == '-') {
        s++;
        neg = 1;
    }

    while(*s != '\0' && cont) {
        int num = char2int(*s);
        if (num < 0 || num > 9) {
            cont = 0;
            continue;
        }
        
        result *= 10;
        result += num;

        s++;
    }

    if (neg) result = -result;

    return result;
}

int isNumber(char *str) {
    if (strlen(str) > MAX_SIZE) return 0;
    
    int i = 0;
    int is_n = 1;
    char num = str[0];

    while(i < MAX_SIZE && num != '\0' && is_n == 1) {
        if (i == 0) {
            if (num < '0' && num != '-') is_n = 0;
            if (num > '9' && num != '-') is_n = 0;
        } else {
            if (num < '0') is_n = 0;
            if (num > '9') is_n = 0;
        }
        
        i++;
        num = str[i];
    }

    return is_n;
}
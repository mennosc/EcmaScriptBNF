#include <stdio.h>
#include <stdlib.h>

char *intToCharP(int value) {
    int length = snprintf(NULL, 0, "%d", value);
    char *string = malloc(length + 1);
    snprintf(string, length + 1, "%d", value);

    return string;
};
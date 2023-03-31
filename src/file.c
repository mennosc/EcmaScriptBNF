#include <stdio.h>
#include <stdlib.h>
#include "../includes/file.h"

char *readFile(const char *path) {
    FILE *input = fopen(path, "r");

    fseek(input, 0L, SEEK_END);
    size_t fileSize = ftell(input);
    fseek(input, 0L, SEEK_SET);

    char *buffer = malloc((fileSize + 1) * sizeof(char));
    if(buffer) {
        fread(buffer, sizeof(char), fileSize, input);
    }

    buffer[fileSize] = '\0';
    return buffer;
}
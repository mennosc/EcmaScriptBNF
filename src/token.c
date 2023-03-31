#include <stdio.h>
#include <stdlib.h>

#include "../includes/token.h"

Token *CreateToken(char *value, TOKEN_TYPES type) {
    Token *token = malloc(sizeof(Token));
    token->value = value;
    token->type = type;

    return token;
}

void freeToken(Token *token) {
    free(token);
}

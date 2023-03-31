#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
    NUMBER,
    PLUS,
    MINUS,
    TIMES,
    DIVIDE,
    IDENTIFIER,
    END_OF_FILE,
} TOKEN_TYPES;

typedef struct {
    TOKEN_TYPES type;
    char *value;
} Token;

Token *CreateToken(char *value, TOKEN_TYPES type);
void freeToken(Token *token);

#endif
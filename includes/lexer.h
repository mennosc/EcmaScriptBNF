#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include "lexer.h"

typedef struct {
    char *source;
    int sourceSize;
    int index;
} Lexer;

void LexerSkipWhitespace(Lexer *lexer);
void printTokenType(Token *token);
Lexer *createLexer(char *source);
Token *parse_identifier(Lexer *lexer);
Token *parse_number(Lexer *lexer);
Token *advanceLexerReturnToken(Lexer *lexer, Token *token);
Token *get_token(Lexer *lexer);

#endif
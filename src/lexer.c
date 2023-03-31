#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../includes/token.h"
#include "../includes/lexer.h"
#include "../includes/macro.h"

Lexer *createLexer(char *source) {
    Lexer *lexer = malloc(sizeof(lexer));
    lexer->source = source;
    lexer->index = 0;
    lexer->sourceSize = strlen(source);

    return lexer;
}

Token *advanceLexerReturnToken(Lexer *lexer, Token *token) {
    if(lexer->index < lexer->sourceSize) {
        lexer->index++;
        return token;
    }
    return CreateToken("", END_OF_FILE);
}

void advanceLexer(Lexer *lexer) {
    if(lexer->index < lexer->sourceSize) {
        lexer->index++;
    }
}

void LexerSkipWhitespace(Lexer *lexer) {
    while(lexer->source[lexer->index] == 9 || lexer->source[lexer->index] == 11 || lexer->source[lexer->index] == 14 || lexer->source[lexer->index] == 32) {
        advanceLexer(lexer);
    }
}

Token *parse_number(Lexer *lexer) {
    int value = 0;
    while(isdigit(lexer->source[lexer->index])) {
        value = value * 10 + (lexer->source[lexer->index] - '0');
        advanceLexer(lexer);
    }

    return CreateToken(intToCharP(value), NUMBER);
}

Token *parse_identifier(Lexer *lexer) {
    char *identifier = calloc(1, sizeof(char));
    while(isalnum(lexer->source[lexer->index])) {
        identifier = realloc(identifier, (strlen(identifier) + 2));
        strcat(identifier, (char[]){lexer->source[lexer->index], 0});
        advanceLexer(lexer);
    }

    return CreateToken(identifier, IDENTIFIER);
}


Token *get_token(Lexer *lexer) {
    char c = lexer->source[lexer->index];
    
    //Todo: Actually return a token instead of just the TokenType
    if(c == '+') {
        return advanceLexerReturnToken(lexer, CreateToken("+", PLUS));
    } else if(c == '-') {
        return advanceLexerReturnToken(lexer, CreateToken("-", MINUS));
    } else if(c == '*') {
        return advanceLexerReturnToken(lexer, CreateToken("*", TIMES));
    } else if(c == '/') {
        return advanceLexerReturnToken(lexer, CreateToken("+", DIVIDE));
    } 
  
    if(isdigit(c)) {
        return parse_number(lexer);
    }

    if(isalnum(c)) {
        return parse_identifier(lexer);
    }

    if(lexer->index == lexer->sourceSize) {
        return CreateToken("", END_OF_FILE);
    }
}

void printTokenType(Token *token) {
    switch(token->type) {
        case NUMBER:
            printf("[Lexer] Type: Number\t Value: %s\n", token->value);
            break;
        case PLUS:
            printf("[Lexer] Type: Plus\t Value: %s\n", token->value);
            break;
        case MINUS:
            printf("[Lexer] Type: Minus\t Value: %s\n", token->value);
            break;
        case TIMES:
            printf("[Lexer] Type: Times\t Value: %s\n", token->value);
            break;
        case DIVIDE:
            printf("[Lexer] Type: Divide\t Value: %s\n", token->value);
            break;
        case IDENTIFIER:
            printf("[Lexer] Type: Identifier\t Value: %s\n", token->value);
            break;
        case END_OF_FILE:
            printf("[Lexer] Type: END_OF_FILE\t Value: %s\n", token->value);
            break;
    }
}
#include <stdio.h>
#include <string.h>

#include "../includes/lexer.h"
#include "../includes/file.h"
#include "../includes/token.h"

int main(int argc, char *argv[]) {
    //getting input from 'expressions.txt'
    char *file = readFile("../expressions.txt");
    //Creating the lexer to tokenize the input
    Lexer *lexer = createLexer(file);

    Token *result;
    while((result = get_token(lexer)) && result->type != END_OF_FILE) {
        LexerSkipWhitespace(lexer);

        printTokenType(result);
    }

    printTokenType(result);

    printf("%s\n", file);
}
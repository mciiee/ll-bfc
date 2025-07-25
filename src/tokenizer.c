#include <stdint.h>
#include <stdio.h>

#define TOKEN_CONSTS
#ifndef _TOKEN_DYANMIC_ARRAY_H
#include "token_dynamic_array.h"
#endif


#ifndef _TOKEN_H
#include "token.h"
#endif

#ifndef INITIAL_TOKEN_DYNAMIC_ARRAY_SIZE
#define INITIAL_TOKEN_DYNAMIC_ARRAY_SIZE 256
#endif

#include "tokenizer.h"

[[nodiscard("Dynamically allocated memory")]] TokenDynamicArray *tokenize(FILE *stream){
    TokenDynamicArray *tokens = TokenDynamicArray_new(INITIAL_TOKEN_DYNAMIC_ARRAY_SIZE);
    Token lastToken = {0};
    for (char input_char = '\0'; !feof(stream);) {
        input_char = fgetc(stream);
        switch (input_char) {
            case '>':
                lastToken = INCREMENT_DP_TOKEN;
                break;
            case '<':
                lastToken = DECREMENT_DP_TOKEN;
                break;
            case '+':
                lastToken = INCREMENT_CELL_TOKEN;
                break;
            case '-':
                lastToken = DECREMENT_CELL_TOKEN;
                break;
            case '.':
                lastToken = OUTPUT_CELL_TOKEN;
                break;
            case ',':
                lastToken = INPUT_CELL_TOKEN;
                break;
            case '[':
                lastToken = JUMP_FORWARD_TOKEN;
                break;
            case ']':
                lastToken = JUMP_BACWARD_TOKEN;
                break;
            default:
                lastToken = (Token){.type = COMMENT, .val = {.symbol = input_char}};
                break;
        }
        TokenDynamicArray_append(tokens, &lastToken);
    }
    TokenDynamicArray_append(tokens, &END_OF_FILE_TOKEN);
    return tokens;
}


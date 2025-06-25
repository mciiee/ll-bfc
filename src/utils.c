#include "utils.h"

#include <stdio.h>

void printToken(const Token *const token){
    printf("\nToken {\n\ttype: ");
    switch (token->type) {
        case INCREMENT_DP:
            printf("INCREMENT_DP\n\tval: %i\n}", token->val.step);
            break;
        case DECREMENT_DP:
            printf("DECREMENT_DP\n\tval: %i\n}", token->val.step);
            break;
        case INCREMENT_CELL:
            printf("INCREMENT_CELL\n\tval: %i\n}", token->val.step);
            break;
        case DECREMENT_CELL:
            printf("DECREMENT_CELL\n\tval: %i\n}", token->val.step);
            break;
        case INPUT_CELL:
            printf("INPUT_CELL\n\tval: %p\n}", token->val.ptr);
            break;
        case OUTPUT_CELL:
            printf("OUTPUT_CELL\n\tval: %p\n}", token->val.ptr);
            break;
        case JUMP_FORWARD:
            printf("JUMP_FORWARD\n\tval: %p\n}", token->val.ptr);
            break;
        case JUMP_BACKWARD:
            printf("JUMP_BACKWARD\n\tval: %p\n}", token->val.ptr);
            break;
        case END_OF_FILE:
            printf("END_OF_FILE\n\tval: %i\n}", token->val.step);
            break;
        case COMMENT:
            printf("COMMENT\n\tval: '%c'\n}", token->val.symbol);
            break;
    }
    printf("\n");
}

void printTokens(const TokenDynamicArray *tokens){
    for (size_t i = 0; i < tokens->occupied; i++) {
        printToken(&tokens->tokens[i]);
    }
}

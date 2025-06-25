#pragma once
#include <stdint.h>

#ifndef _TOKEN_H
#define _TOKEN_H
#endif

enum TokenType: uint64_t {
    INCREMENT_DP,
    DECREMENT_DP,
    
    INCREMENT_CELL,
    DECREMENT_CELL,

    OUTPUT_CELL,
    INPUT_CELL,

    JUMP_FORWARD,
    JUMP_BACKWARD,

    COMMENT,

    END_OF_FILE
};

typedef union TokenValue {
    void *ptr;
    int step;
    char symbol;
} TokenValue;

typedef struct Token {
    enum TokenType type;
    TokenValue val;
} Token;

// #define TOKEN_CONSTS
#ifdef TOKEN_CONSTS

const Token INCREMENT_DP_TOKEN = {
    .type = INCREMENT_DP,
    .val = {.step = 1}
};

const Token DECREMENT_DP_TOKEN = {
    .type = DECREMENT_DP,
    .val = {.step = 1}
};

const Token INCREMENT_CELL_TOKEN = {
    .type = INCREMENT_CELL,
    .val = {.step = 1}
};

const Token DECREMENT_CELL_TOKEN = {
    .type = DECREMENT_CELL,
    .val = {.step = 1}
};

const Token OUTPUT_CELL_TOKEN = {
    .type = OUTPUT_CELL,
    .val = {.ptr = nullptr}
};

const Token INPUT_CELL_TOKEN = {
    .type = OUTPUT_CELL,
    .val = {.ptr = nullptr}
};

const Token JUMP_FORWARD_TOKEN = {
    .type = JUMP_FORWARD,
    .val = {.ptr = nullptr}
};
const Token JUMP_BACWARD_TOKEN = {
    .type = JUMP_BACKWARD,
    .val =  {.ptr = nullptr}
};

const Token END_OF_FILE_TOKEN = {
    .type = END_OF_FILE,
    .val = {.step = -1}
};
#endif

#pragma once
#include <stddef.h>

#ifndef _TOKEN_H
#include "token.h"
#endif

#ifndef _TOKEN_DYANMIC_ARRAY_H
#define _TOKEN_DYANMIC_ARRAY_H
#endif

typedef struct TokenDynamicArray {
    Token *tokens;
    size_t capacity;
    size_t occupied;
} TokenDynamicArray;

TokenDynamicArray *TokenDynamicArray_new(size_t capacity);

void TokenDynamicArray_free(TokenDynamicArray *array);

TokenDynamicArray *TokenDynamicArray_append(TokenDynamicArray *array, const Token *token);

TokenDynamicArray *TokenDynamicArray_resize(TokenDynamicArray *array, size_t capacity);

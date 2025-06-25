#include "token_dynamic_array.h"
#include <stdlib.h>

TokenDynamicArray *TokenDynamicArray_new(size_t capacity){
    TokenDynamicArray *array = malloc(sizeof(TokenDynamicArray));
    array->occupied = 0;
    array->capacity = capacity;
    array->tokens = calloc(capacity, sizeof(Token));
    if (array->tokens == nullptr) {
        return nullptr;
    }
    return array;
}

void TokenDynamicArray_free(TokenDynamicArray *array){
    free(array->tokens);
    free(array);
}


TokenDynamicArray *TokenDynamicArray_resize(TokenDynamicArray *array, size_t capacity){
    array->capacity = capacity;
    if (capacity < array->occupied) {
        array->occupied = capacity;
    }
    array->tokens = realloc(array->tokens, capacity * sizeof(Token));
    if (array->tokens == nullptr) {
        return nullptr;
    }
    return array;
}



TokenDynamicArray *TokenDynamicArray_append(TokenDynamicArray *array, const Token *token){
    if (array->capacity >= array->occupied) {
        array = TokenDynamicArray_resize(array, array->capacity * 1.5);
    }
    array->tokens[array->occupied] = *token;
    array->occupied++;

    return array;
}

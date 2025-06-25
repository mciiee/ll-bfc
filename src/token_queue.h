#ifdef _TOKEN_QUEUE_H
#define _TOKEN_QUEUE_H
#endif

#ifndef _TOKEN_H
#include "token.h"
#endif

typedef struct TokenQueueNode {
    Token *token;
    struct TokenQueueNode *next;
    struct TokenQueueNode *prev;
} TokenQueueNode;

typedef struct TokenQueue {
    TokenQueueNode *head;
    TokenQueueNode *tail;
} TokenQueue;


TokenQueueNode *TokenQueueNode_new(Token *token);
void TokenQueueNode_free(TokenQueueNode *node);
void TokenQueueNode_link(TokenQueueNode *prev, TokenQueueNode *next);


[[nodiscard("Dynamically allocated memory")]]
TokenQueue *TokenQueue_new(TokenQueueNode *head, TokenQueueNode *tail);
void TokenQueue_free(TokenQueue *queue);
TokenQueueNode *TokenQueue_enqueue(TokenQueue *queue, TokenQueueNode *node);
[[nodiscard("Dynamically allocated memory")]]
TokenQueueNode *TokenQueue_dequeue(TokenQueue *queue);

#include "token_queue.h"
#include <stdlib.h>

[[nodiscard("Dynamically-allocated memory")]] 
TokenQueueNode *TokenQueueNode_new(Token *token){
    TokenQueueNode *node = malloc(sizeof(TokenQueueNode));
    node->token = token;
    node->next = nullptr;
    node->prev = nullptr;
    return node;
}
void TokenQueueNode_free(TokenQueueNode *node){
    free(node);
}

void TokenQueueNode_link(TokenQueueNode *prev, TokenQueueNode *next) {
    if(prev->next != nullptr){
        prev->next->prev = nullptr;
    }
    prev->next = next;
    if(next->prev != nullptr){
        next->prev->next = nullptr;
    }
    next->prev = prev;
}

void TokenQueueNode_freeRec(TokenQueueNode *node){
    if (node->next == nullptr) {
        free(node);
        return;
    }
    TokenQueueNode_freeRec(node->next);
    free(node);
}

TokenQueue *TokenQueue_new(TokenQueueNode *head, TokenQueueNode *tail){
    TokenQueue *queue = malloc(sizeof(TokenQueue));
    if (tail == nullptr) {
        queue->head = head;
        queue->tail = head;
        return queue;
    }
    TokenQueueNode_link(head, tail);
    queue->head = head;
    queue->tail = tail;
    return queue;
}

void TokenQueue_free(TokenQueue *queue){
    TokenQueueNode_freeRec(queue->head);
}

TokenQueueNode *TokenQueue_enqueue(TokenQueue *queue, TokenQueueNode *node){
    queue->tail->next = node;
    node->prev->next = nullptr;
    node->prev = queue->tail;
    queue->tail = node;
    return node;
}

[[nodiscard("Dynamically allocated memory")]]
TokenQueueNode *TokenQueue_dequeue(TokenQueue *queue){
    TokenQueueNode *tail = queue->tail;
    if (queue->tail == nullptr && queue->head == nullptr) {
        return nullptr;
    }
    else if (queue->tail == nullptr) {
        tail = queue->head;
        queue->head = nullptr;
        return tail;
    }
    if (queue->tail->prev == queue->head) {
        queue->tail = nullptr;
        return tail;
    }
    queue->tail = queue->tail->prev;
    return tail;
}

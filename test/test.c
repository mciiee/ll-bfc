#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>

#ifndef _TOKEN_QUEUE_H
#include "token_queue.h"
#endif

static void two_queue_test(void **state){
    (void)state;
    
    TokenQueueNode *head = TokenQueueNode_new(nullptr);
    TokenQueueNode *tail = TokenQueueNode_new(nullptr);
    auto queue = TokenQueue_new(head, tail);

    TokenQueueNode *popped_tail = TokenQueue_dequeue(queue);
    assert_true(popped_tail == tail);
    
    TokenQueueNode_free(popped_tail);    
    TokenQueue_free(queue);
}

static void one_queue_test(void **state){
    (void)state;
    
    TokenQueueNode *tail = TokenQueueNode_new(nullptr);
    auto queue = TokenQueue_new(nullptr, tail);

    TokenQueue_free(queue);
}

int main(void){
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(one_queue_test),
        cmocka_unit_test(two_queue_test)
    };

    return cmocka_run_group_tests(tests, nullptr, nullptr);
}

#pragma once

#ifndef _TOKENIZER_H
#define _TOKENIZER_H
#endif

#ifndef _TOKEN_DYANMIC_ARRAY_H
#include "token_dynamic_array.h"
#endif

#include <stdio.h>
TokenDynamicArray *tokenize(FILE *stream);

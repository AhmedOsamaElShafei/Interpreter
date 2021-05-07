#include <stdlib.h>
#include "stack.h"

struct stack {
    Object *arr; // using a primitive struct to ensure passing copies for the stack
    unsigned int top, capacity, e_size;
};

Stack *stack_initialize(unsigned int c) {
    Stack *s = malloc(sizeof(Stack));
    s->arr = malloc(sizeof(Object));
    s->top = 0;
    s->capacity = c;
    return s;
}

Object pop(Stack *s) {
    stack_errno = s->top > 0 ? 0 : 2;
    return (stack_errno ? (Object) {} : *(Object *) ((char*) s->arr + (--s->top * s->e_size)));
}

void push(Stack *s, Object e) {
    stack_errno = s->top == s->capacity;
    if (!stack_errno) *(Object *) ((char*) s->arr + (s->top++ * s->e_size)) = e;
}

Object top(Stack *s) {
    stack_errno = s->top > 0 ? 0 : 2;
    return (stack_errno ? (Object) {} : *(Object *) ((char*) s->arr + ((s->top-1) * s->e_size)));
}

int stack_isEmpty(Stack *s) {
    return !s->top;
}

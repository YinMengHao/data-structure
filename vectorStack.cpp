//
//  main.cpp
//  03-VectorStack
//
//  Created by menghao on 2023/3/7.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

typedef struct vector {
    int *data;
    int count;
} Vector;

typedef struct stack {
    Vector *vector;
    int top, count, size;
} Stack;

#pragma mark - vector
Vector *initVector(int n) {
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->data = (int *)malloc(sizeof(int) * n);
    v->count = n;
    return v;
}

void clearVector(Vector *v) {
    free(v->data);
    return;
}

int insertTail(Vector *v, int pos, int val) {
    if (v == NULL || pos >= v->count) {
        return 0;
    }
    v->data[pos] = val;
    return 1;
}

#pragma mark - stack
Stack *initStack(int n) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->vector = initVector(n);
    stack->size = n;
    stack->top = -1;
    stack->count = 0;
    return stack;
}

int empty(Stack *s) {
    return s->top == -1;
}

void clearStack(Stack *s) {
    clearVector(s->vector);
    free(s->vector);
    s->top = -1;
    s->count = s->size = 0;
    return;
}

int push(Stack *s, int val) {
    if (s == NULL || s->top == s->size) {
        return 0;
    }
    s->top += 1;
    insertTail(s->vector, s->top, val);
    s->count += 1;
    return 1;
}

int pop(Stack *s) {
    if (s->top == -1) {
        return 0;
    }
    s->top -= 1;
    s->count -= 1;
    return 1;
}

void outputStack(Stack *s) {
    if (s->top == -1) {
        return;
    }
    printf("stack values: \n");
    int n = 0;
    while (n <= s->top) {
        printf("%4d", s->vector->data[n]);
        n += 1;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
#define MAX_OP 10
    Stack *stack = initStack(10);
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        push(stack, val);
        
    }
    outputStack(stack);

    pop(stack);


    outputStack(stack);
    
    return 0;
}

//
//  main.cpp
//  01-顺序表实现栈
//
//  Created by menghao on 2023/2/25.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

typedef struct vector {
    int *data;
    int size;
} vector;

typedef struct Queue {
    vector *data;
    int size, count, head, tail;
} Queue;

#pragma mark - vector
vector *initVector(int n) {
    vector *v = (vector *)malloc(sizeof(vector));
    v->size = n;
    v->data = (int *)malloc(sizeof(int) * n);
    return v;
}

void clearVector(vector *v) {
    if (v == NULL) {
        return;
    }
    free(v->data);
    free(v);
    return;
}

int insertVector(vector *v, int pos, int val) {
    if (v == NULL || pos < 0 || pos >= v->size) {
        return 0;
    }
    v->data[pos] = val;
    return 1;
}

int vectorSeek(vector *v, int pos) {
    if (pos < 0 || pos >= v->size) {
        return -1;
    }
    return v->data[pos];
}


#pragma mark - queue
Queue *initQueue(int n) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->data = initVector(n);
    queue->size = n;
    queue->head = queue->tail = queue->count = 0;
    return queue;
}

int empty(Queue *q) {
    return q->count == 0;
}

int push(Queue *q, int val) {
    if (q == NULL || q->count == q->size) {
        return 0;
    }
    insertVector(q->data, q->tail, val);
    q->tail += 1;
    if (q->tail == q->size) {
        q->tail = 0;
    }
    q->count += 1;
    return 1;
}

int pop(Queue *q) {
    if (empty(q)) {
        return 0;
    }
    q->head += 1;
    q->count -= 1;
    return 1;
}

int front(Queue *q) {
    return vectorSeek(q->data, q->head);
}

void clearQueue(Queue *q) {
    if (q == NULL) { return; }
    clearVector(q->data);
    q->count = q->head = q->tail = 0;
    free(q);
}

void outputQueue(Queue *q) {
    printf("Queue: ");
    for (int i = 0; i < q->count; i++) {
        printf("%4d", vectorSeek(q->data, (q->head + i) % q->size));
    }
    printf("\n");
    return;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
#define MAX_OP 10
    Queue *q = initQueue(5);
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 5, val = rand() % 100;
//        switch (op) {
//            case 0:
//                printf("front of queue : %d\n", front(q));
//                pop(q);
//                break;
//            case 1:
//            case 2:
//            case 3:
//            case 4:
//                printf("push %d to queue\n", val);
//                push(q, val);
//        }
//        outputQueue(q);
    }
    push(q, 1);
    push(q, 2);
    push(q, 3);
    push(q, 4);
    push(q, 5);
    pop(q);
    
    outputQueue(q);
    push(q, 8);
    outputQueue(q);


    pop(q);
    outputQueue(q);

    pop(q);
    outputQueue(q);
    
    pop(q);
    outputQueue(q);
    pop(q);
    outputQueue(q);
    
    pop(q);
    outputQueue(q);
    pop(q);
    outputQueue(q);

    
    return 0;
}

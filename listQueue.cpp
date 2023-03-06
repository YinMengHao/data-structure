//
//  main.cpp
//  02-链表实现queue
//
//  Created by menghao on 2023/3/6.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef struct node {
    int data;
    struct node *next;
} Node;

// head头节点 不存储数据
typedef struct linkList {
    Node head, *tail;
} LinkList;

typedef struct queue {
    LinkList *l;
    int count;
} Queue;

#pragma mark - linkList
int emptyList(LinkList *list) {
    return list->head.next == NULL;
}

LinkList *initLinkList() {
    LinkList *list = (LinkList *)malloc(sizeof(LinkList));
    list->head.next = NULL;
    list->tail = &(list->head);
    return list;
}

int frontList(LinkList *list) {
    if (emptyList(list)) {
        return 0;
    }
    return list->head.next->data;
}

int insertTail(LinkList *list, int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    list->tail->next = node;
    list->tail = node;
    return 1;
}

int deleteHead(LinkList *list) {
    if (list == NULL || emptyList(list)) {
        return 0;
    }
    Node *p = list->head.next;
    list->head.next = list->head.next->next;
    if (p == list->tail) {
        list->tail = &(list->head);
    }
    free(p);
    return 1;
}

void clearLinkList(LinkList *list) {
    Node *p = list->head.next, *q;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    free(list);
    return;
}

#pragma mark - queue
Queue *initQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->count = 0;
    q->l = initLinkList();
    return q;
}

int empty(Queue *q) {
    return q->count == 0;
}

int push(Queue *q, int val) {
    insertTail(q->l, val);
    return 1;
}

int pop(Queue *q) {
    if (q == NULL) {
        return 0;
    }
    deleteHead(q->l);
    return 1;
}

int front(Queue *q) {
    if (q == NULL) {
        return 0;
    }
    return frontList(q->l);
}

void clearQueue(Queue *q) {
    if (q == NULL) { return; }
    clearLinkList(q->l);
    free(q);
    return;
}

void outputQueue(Queue *queue) {
    if (emptyList(queue->l)) {
        return;
    }
    Node *p = queue->l->head.next, *q;
    while (p) {
        q = p->next;
        printf("%4d ", p->data);
        p = q;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
#define MAX_OP 10
    Queue *q = initQueue();
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 5, val = rand() % 100;
        switch (op) {
            case 0:
                printf("front of queue : %d\n", front(q));
                pop(q);
                break;
            case 1:
            case 2:
            case 3:
            case 4:
                printf("push %d to queue\n", val);
                push(q, val);
        }
        outputQueue(q);
    }
    
    return 0;
}

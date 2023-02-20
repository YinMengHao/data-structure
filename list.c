//
//  main.c
//  链表
//
//  Created by menghao on 2023/2/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_OP 10

typedef struct Node {
    struct Node *next;
    int val;
} Node;


// 初始化一个节点node
Node *initNode(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        printf("初始化node失败\n");
        return NULL;
    }
    node->val = value;
    node->next = NULL;
    return node;
}

Node *insertNode(Node *head, int pos, int val) {
    Node *node = initNode(val);
    if (pos == 0) {
        node->next = head;
        return node;
    }
    Node *temp = head;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
    }
    node->next = temp->next;
    temp->next = node;
    return head;
}

void clearNode(Node *head) {
    if (head == NULL) {
        return;
    }
    Node *pNode = NULL;
    while (head) {
        pNode = head->next;
        free(head);
        head = pNode;
    }
}

void output_node(Node *head) {
    int n = 0;
    for (Node *p = head; p != NULL; p = p->next) {
        n++;
    }
    for (int i = 0; i < n; i++) {
        printf("%3d", i);
        printf("  ");
    }
    printf("\n");
    for (Node *p = head; p; p=p->next) {
        printf("%3d", p->val);
        printf("->");
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    srand((unsigned)time(0));
    Node *head = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int pos = rand() % (i + 1), value = rand() % 100;
        printf("insert %d at %d to list\n", value, pos);
        head = insertNode(head, pos, value);
        output_node(head);
    }
    printf("\n");
    
    return 0;
}

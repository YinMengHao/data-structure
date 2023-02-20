//
//  main.cpp
//  反转链表
//
//  Created by menghao on 2023/2/19.
//

#include <iostream>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
} ListNode;


/*
 // 递归方式实现
 if (head == nullptr || head->next == nullptr) { return head; };
 ListNode *tail = head->next;
 ListNode *new_head = reverseList(head->next);
 head->next = tail->next;
 tail->next = head;
 return new_head;
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 从头节点插入 new_head为头节点
        ListNode new_head, *p = head, *q;
        new_head.next = nullptr;
        while (p) {
            q = p->next;
            p->next = new_head.next;
            new_head.next = p;
            p = q;
        }
        return new_head.next;
    }
};

void logList(ListNode *head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->next = nullptr;
    head->val = 10;
    ListNode *p = head;
    
    for (int i = 0; i < 5; i++) {
        ListNode *node = (ListNode *)malloc(sizeof(ListNode));
        node->next = nullptr;
        node->val = i;
        p->next = node;
        p = p->next;
    }
    logList(head->next);
    
    Solution solu;
    ListNode *head_node = solu.reverseList(head->next);
    logList(head_node);

    
    return 0;
}

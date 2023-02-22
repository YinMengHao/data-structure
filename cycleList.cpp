//
//  main.cpp
//  环形链表
//
//  Created by menghao on 2023/2/22.
//

#include <iostream>
using namespace std;
/*
力扣： https://leetcode.cn/problems/linked-list-cycle/
 给一个链表头节点head，判断链表中是否有环。
/// 解题思路：
 利用快慢指针
 */

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p = head, *q = head;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
            if (p == q) {
                return true;
            }
        }
        return false;
    }
};

ListNode *createList(int count, bool hasCycle) {
    if (count <= 0 || (hasCycle && count == 1)) {
        cout << "传入参数非法" << endl;
        return nullptr;
    }
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->next = nullptr;
    // 临时结点
    ListNode *p = head;
    ListNode *cyclePtr = nullptr;
    for(int i = 0; i < count; i++) {
        ListNode *node = (ListNode *)malloc(sizeof(ListNode));
        if (node) {
            node->next = nullptr;
            node->val = i;
            p->next = node;
            p = p->next;
            if (i == 1 && hasCycle) {
                cyclePtr = node;
            }
        }
    }
    if (hasCycle) {
        p->next = cyclePtr;
    }
    return head->next;
}

void printList(ListNode *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    
    
    ListNode *head = createList(5, false);
    
    Solution solu;
    cout << solu.hasCycle(head) << endl;

    
    return 0;
}

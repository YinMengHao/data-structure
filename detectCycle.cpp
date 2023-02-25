//
//  main.cpp
//  环形链表相遇问题
//
//  Created by menghao on 2023/2/25.
//

/*
 力扣：https://leetcode.cn/problems/linked-list-cycle-ii/
 给定一个链表的头节点，返回入环的第一个节点 如果无环，返回null
 eg：
 输入：head = [3,2,0,-4], pos = 1
 输出：返回索引为 1 的链表节点
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

ListNode *createList(int count, bool hasCycle, int pos = 1) {
    if (count <= 0 || (hasCycle && count == 1) || (pos >= count - 1 && hasCycle)) {
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
            if (hasCycle && i == pos) {
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

/// 快慢指针法
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return head;
        ListNode *p = head, *q = head;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
            if (p == q) {
                // 有环
                p = head;
                while (p != q) {
                    p = p->next;
                    q = q->next;
                }
                return p;
            }
        }
        return NULL;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ListNode *head = createList(4, true, 2);
//    printList(head);
    
    Solution solu;
    cout << solu.detectCycle(head)->val << endl;
    
    return 0;
}

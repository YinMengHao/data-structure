//
//  main.cpp
//  旋转链表
//
//  Created by menghao on 2023/2/22.
//

#include <iostream>
using namespace std;

/*
 力扣： https://leetcode.cn/problems/rotate-list/
 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
eg:
 输入：head = [1,2,3,4,5], k = 2
 输出：[4,5,1,2,3]
 解决思路：
 双指针同步平移
 */

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

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


class Solution {
public:
    int getLength(ListNode *head) {
        int len = 0;
        while (head) {
            len += 1;
            head = head->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (k <= 0 || head == nullptr) {
            return head;
        }
        int length = getLength(head);
        k %= length;
        ListNode *p = head, *q = head;
        // 将p定位到k+1处，随后向后移动k位，p指向null,q即为新链表的最后一个节点
        for (int i = 0; i <= k; i++) p = p->next;
        // 双指针向后平移
        while (p) {
            q = q->next;
            p = p->next;
        }
        // 拆分成两个链表
        p = q->next;
        q->next = nullptr;
        
        ListNode *new_head = p;
        
        while (p->next) {
            p = p->next;
        }
        p->next = head;
        return new_head;
    }
};


int main(int argc, const char * argv[]) {
    
    
    ListNode *head = createList(5, false);
    printList(head);
    
    Solution solu;
    ListNode *new_head = solu.rotateRight(head, 2);
    printList(new_head);
    
    return 0;
}

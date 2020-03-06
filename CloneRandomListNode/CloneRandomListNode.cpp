// CloneRandomListNode.cpp : 
// 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。

#include <iostream>

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (pHead == NULL) {
            return NULL;
        }
        //复制链表，挂在原链表的后面
        RandomListNode* cur = pHead;
        while (cur != NULL) {
            RandomListNode* clone = new RandomListNode(cur->label);
            RandomListNode* next = cur->next;
            cur->next = clone;
            clone->next = next;
            cur = next;
        }

        //将复制链表的random指针指好
        cur = pHead;
        while (cur != NULL) {
            cur->next->random = cur->random == NULL ? NULL : cur->random->next;
            cur = cur->next->next;
        }

        //将复制的链表拆除
        cur = pHead;
        RandomListNode* pCloneHead = pHead->next;
        while (cur != NULL) {
            RandomListNode* clone = cur->next;
            cur->next = clone->next;
            clone->next = clone->next == NULL ? NULL : clone->next->next;
            cur = cur->next;
        }

        return pCloneHead;
    }
};

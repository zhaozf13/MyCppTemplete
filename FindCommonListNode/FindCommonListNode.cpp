// FindCommonListNode.cpp : 
// 寻找两个链表的第一个公共节点
// 1.判断两个链表有无环，会相交的情况包括：1）两个均无环 2）两个均有环
// 2.两个均无环时，先分别遍历到底，如果end1 == end2，则相交，长的先走|len1-len2|步，再同时走，到相遇
// 3.两个均有环，分两种情况，1）loop1 == loop2， 则与2中情况类似，只是end变为了入环节点
//                         2) loop1 != loop2， 则1先循环，若在循环中遇到loop2，则相交，若没遇到，则不相交 
#include <iostream>

using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
	//判断是否有环，并返回入环节点
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (pHead == NULL || pHead->next == NULL || pHead->next->next == NULL) {
            return NULL;
        }
        ListNode* fast = pHead->next->next;
        ListNode* low = pHead->next;
        //注意判断有无环时放在循环里来判断，主要判断需要设置为两个节点是否相遇
        while (fast != low) {
            if (fast->next == NULL || fast->next->next == NULL) {
                return NULL;
            }
            fast = fast->next->next;
            low = low->next;
        }
        fast = pHead;
        while (fast != low) {
            fast = fast->next;
            low = low->next;
        }
        return fast;
    }

    //寻找两个无环链表相交节点
    ListNode* noLoop(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == NULL || pHead2 == NULL) return NULL;
        ListNode* cur1 = pHead1;
        ListNode* cur2 = pHead2;
        int dif = 0;
        while (cur1 != NULL) {
            dif++;
            cur1 = cur1->next;
        }
        while (cur2 != NULL) {
            dif--;
            cur2 = cur2->next;
        }
        if (cur1 != cur2) return NULL;
        cur1 = (dif > 0) ? pHead1 : pHead2;
        cur2 = (cur1 == pHead1) ? pHead2 : pHead1;
        dif = (dif > 0) ? dif : (-1 * dif);
        while (dif != 0) {
            cur1 = cur1->next;
            dif--;
        }
        while (cur1 != cur2) {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }

    //寻找两个有环链表的相交节点
    ListNode* bothLoop(ListNode* pHead1, ListNode* loop1, ListNode* pHead2, ListNode* loop2) {
        if (pHead1 == NULL || pHead2 == NULL) return NULL;
        ListNode* cur1 = NULL;
        ListNode* cur2 = NULL;
        if (loop1 == loop2) {
            int dif = 0;
            cur1 = pHead1;
            cur2 = pHead2;
            while (cur1 != loop1) {
                dif++;
                cur1 = cur1->next;
            }
            while (cur2 != loop2) {
                dif--;
                cur2 = cur2->next;
            }
            cur1 = (dif > 0) ? pHead1 : pHead2;
            cur2 = (cur1 == pHead1) ? pHead2 : pHead1;
            dif = (dif > 0) ? dif : (-1 * dif);
            while (dif != 0) {
                cur1 = cur1->next;
                dif--;
            }
            while (cur1 != cur2) {
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            return cur1;
        }
        else {
            cur1 = loop1->next;
            while (cur1 != loop1) {
                if (cur1 == loop2) {
                    return loop1;
                }
                cur1 = cur1->next;
            }
            return NULL;
        }

    }


	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == NULL || pHead2 == NULL) return NULL;
        ListNode* loop1 = EntryNodeOfLoop(pHead1);
        ListNode* loop2 = EntryNodeOfLoop(pHead2);
        if (loop1 == NULL && loop2 == NULL) {
            return noLoop(pHead1, pHead2);
        }
        if (loop1 != NULL && loop2 != NULL) {
            return bothLoop(pHead1, loop1, pHead2, loop2);
        }
        return NULL;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}


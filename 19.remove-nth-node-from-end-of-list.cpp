/*
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (34.06%)
 * Total Accepted:    233.6K
 * Total Submissions: 686K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the nth node from the end of list and return its
 * head.
 *
 * For example,
 *
 *
 * ⁠  Given linked list: 1->2->3->4->5, and n = 2.
 *
 * ⁠  After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 *
 *
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
 *
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// #include "header.h"
class Solution {
    int len(ListNode *head) {
        ListNode *p = head;
        int len = 0;
        while (p) {
            ++len;
            p = p->next;
        }
        return len;
    }

    void removeNthFromHead(ListNode *head, int n) {
        ListNode *pre, *p = head;
        while (--n) {
            pre = p;
            p = p->next;
        }
        pre->next = p->next;
    }

public:
    ListNode* removeNthFromEnd(ListNode *head, int n) {
       int m = len(head) - n + 1;
       if (m == 1)
           return head->next;
       removeNthFromHead(head, m);
       return head;
    }
};

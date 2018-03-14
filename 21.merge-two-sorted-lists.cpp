/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (40.72%)
 * Total Accepted:    322K
 * Total Submissions: 790.8K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
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
    void choose(ListNode *p, ListNode* &l) {
        p->val = l->val;
        l = l->next;
    }

public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2)
            return NULL;

        ListNode *head = new ListNode(0);
        ListNode *p = head;

        while (l1 || l2) {
            if (!l1) {
                choose(p, l2);
            } else if (!l2) {
                choose(p, l1);
            } else if (l1->val <= l2->val) {
                choose(p, l1);
            } else {
                choose(p, l2);
            }
            if (l1 || l2) {
                p->next = new ListNode(0);
                p = p->next;
            }
        }
        return head;
    }
};

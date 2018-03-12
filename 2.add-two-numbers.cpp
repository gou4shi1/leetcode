/*
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (28.51%)
 * Total Accepted:    455.7K
 * Total Submissions: 1.6M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * Example
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        int c = 0;
        while (l1 && l2) {
            p->next = new ListNode(c + l1->val + l2->val);
            c = 0;
            p = p->next;
            if (p->val > 9) {
                p->val -= 10;
                ++c;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 || l2) {
            if (l1) {
                p->next = l1;
            } else {
                p->next = l2;
            }
            while (c && p->next) {
                p = p->next;
                p->val += c;
                c = 0;
                if (p->val > 9) {
                    p->val -= 10;
                    ++c;
                }
            }
        }
        if (c) {
            p->next = new ListNode(c);
        }
        return head->next;
    }
};

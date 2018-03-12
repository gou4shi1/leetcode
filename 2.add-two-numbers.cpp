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
        ListNode *head = l1;
        int c = 0;
        while (l1 && l2) {
            l1->val += c + l2->val;
            c = 0;
            if (l1->val > 9) {
                l1->val -= 10;
                ++c;
            }
            if (!l1->next || !l2->next)
                break;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l2->next) {
            l1->next = l2->next;
        }
        while (c && l1->next) {
            l1 = l1->next;
            l1->val += c;
            c = 0;
            if (l1->val > 9) {
                l1->val -= 10;
                ++c;
            }
        }
        if (c) {
            l1->next = new ListNode(c);
        }
        return head;
    }
};

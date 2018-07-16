/*
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (33.86%)
 * Total Accepted:    174.1K
 * Total Submissions: 514.1K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
//#include "header.h"

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;

        ListNode *fp = head, *sp = head, *sp_pre = nullptr, *sp_next;
        while (fp && fp->next) {
            fp = fp->next->next;
            sp_next = sp->next;
            sp->next = sp_pre;
            sp_pre = sp;
            sp = sp_next;
        }

        ListNode *p = sp_pre, *q = sp;
        if (fp) {
            q = sp->next;
        }
        while (p) {
            if (p->val != q->val)
                return false;
            p = p->next;
            q = q->next;
        }
        return true;
    }
};

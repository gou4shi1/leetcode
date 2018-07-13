/*
 * [142] Linked List Cycle II
 *
 * https://leetcode.com/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (30.34%)
 * Total Accepted:    156.8K
 * Total Submissions: 519.1K
 * Testcase Example:  '[]\nno cycle'
 *
 * 
 * Given a linked list, return the node where the cycle begins. If there is no
 * cycle, return null.
 * 
 * 
 * 
 * Note: Do not modify the linked list.
 * 
 * 
 * Follow up:
 * Can you solve it without using extra space?
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
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *sp = head, *fp = head;
        while (fp && fp->next) {
            sp = sp->next;
            fp = fp->next->next;
            if (sp == fp) {
                fp = head;
                while (sp != fp) {
                    sp = sp->next;
                    fp = fp->next;
                }
                return fp;
            }
        }
        return nullptr;
    }
};

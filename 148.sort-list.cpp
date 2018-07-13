/*
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (30.54%)
 * Total Accepted:    140.3K
 * Total Submissions: 455.2K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
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
    void quickSort(ListNode *head, ListNode *tail) {
        if (!head || head == tail)
            return;

        int pivot = head->val;

        ListNode *p = head, *pre_p = nullptr, *q = head->next;
        while (q) {
            if (q->val < pivot) {
                swap(p->val, q->val);
                pre_p = p;
                p = p->next;
            }
            q = q->next;
        }
        if (pre_p)
            quickSort(head, pre_p);

        if (p == tail)
            return;
        q = p;
        while (q && q->val != pivot)
            q = q->next;
        swap(p->val, q->val);
        quickSort(p->next, tail);
    }

public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode *tail = head;
        while (tail->next)
            tail = tail->next;
        quickSort(head, tail);
        return head;
    }
};

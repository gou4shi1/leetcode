/*
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (48.07%)
 * Total Accepted:    377.8K
 * Total Submissions: 785.9K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Reverse a singly linked list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * 
 * 
 * Follow up:
 * 
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
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
    ListNode* recRevList(ListNode *head, ListNode *tail) {
        if (!head)
            return tail;

        ListNode *p = head->next;
        head->next = tail;
        return recRevList(p, head);
    }

    ListNode* recRevList_v1(ListNode *head) {
        if (!head || !head->next)
            return head;

        ListNode *p = head->next;
        head->next = nullptr;
        ListNode *q = recRevList_v1(p);
        p->next = head;
        return q;
    }

public:
    ListNode* reverseList(ListNode* head) {
        //return recRevList(head, nullptr);
        return recRevList_v1(head);
    }
};

/*
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (28.04%)
 * Total Accepted:    209.1K
 * Total Submissions: 745.7K
 * Testcase Example:  '[]'
 *
 * 
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
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
    struct CmpListNodePtrs {
        bool operator()(const ListNode* lhs, const ListNode* rhs) const {
            return lhs->val > rhs->val;
        }
    };

    priority_queue<ListNode*, vector<ListNode*>, CmpListNodePtrs> q;

public:
    ListNode* mergeKLists(const vector<ListNode*>& lists) {
        int n = lists.size();
        for (int i = 0; i < n; ++i) {
            if (lists[i])
                q.push(lists[i]);
        }
        ListNode *head = new ListNode(0);
        ListNode *p = head, *pp;
        if (q.empty())
            return NULL;
        while (!q.empty()) {
            pp = q.top();
            q.pop();
            p->val = pp->val;
            pp = pp->next;
            if (pp)
                q.push(pp);
            if (!q.empty()) {
                p->next = new ListNode(0);
                p = p->next;
            }
        }
        return head;
    }
};

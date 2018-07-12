/*
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (24.21%)
 * Total Accepted:    259.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[2,1,3]'
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * Output: false
 * Explanation: The input is: [5,1,4,null,null,3,6]. The root node's
 * value
 * is 5 but its right child's value is 4.
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//#include "header.h"
// pair
typedef pair<int, int> PII;
#define mp make_pair
#define fi first
#define se second

class Solution {
    bool ans = true;

    PII check(TreeNode* p) {
        if (!ans || !p)
            return mp(0, 0);

        PII ret(p->val, p->val);
        
        if (p->left) {
            PII left = check(p->left);
            if (left.fi >= p->val)
                ans = false;
            ret.se = left.se;
        }
        if (p->right) {
            PII right = check(p->right);
            if (right.se <= p->val)
                ans = false;
            ret.fi = right.fi;
        }
        
        return ret;
    }

public:
    bool isValidBST(TreeNode* root) {
        check(root);
        return ans;
    }
};

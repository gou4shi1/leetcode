/*
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (50.76%)
 * Total Accepted:    304.9K
 * Total Submissions: 597.2K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
class Solution {
    vector<int> ans;

    void dfs(TreeNode* p) {
        if (!p)
            return;
        dfs(p->left);
        ans.push_back(p->val);
        dfs(p->right);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

/*
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (43.40%)
 * Total Accepted:    256.3K
 * Total Submissions: 587.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
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

class Solution {
    void _push(vector<vector<int>> &ans, vector<TreeNode*> &v) {
        if (v.empty())
            return;

        vector<int> t;
        for (TreeNode* p: v)
            t.push_back(p->val);
        ans.push_back(t);
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;

        vector<TreeNode*> last;
        last.push_back(root);
        _push(ans, last);

        while (!last.empty()) {
            vector<TreeNode*> curr;
            for (TreeNode* p: last) {
                if (p->left)
                    curr.push_back(p->left);
                if (p->right)
                    curr.push_back(p->right);
            }
            last = curr;
            _push(ans, last);
        }

        return ans;
    }
};

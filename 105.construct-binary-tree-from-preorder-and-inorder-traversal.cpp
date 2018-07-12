/*
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (35.08%)
 * Total Accepted:    151.3K
 * Total Submissions: 427.7K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    typedef vector<int>::iterator IT;

    map<int, IT> in_map;

    TreeNode* build(IT pre_beg, IT pre_end, IT in_beg, IT in_end) {
        if (pre_beg == pre_end)
            return nullptr;

        int val = *pre_beg;
        TreeNode *p = new TreeNode(val);

        auto it = in_map[val];
        int left_size = it - in_beg;
        p->left = build(pre_beg + 1, pre_beg + 1 + left_size, in_beg, it);
        p->right = build(pre_beg + 1 + left_size, pre_end, it + 1, in_end);

        return p;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (auto it = inorder.begin(); it != inorder.end(); ++it)
            in_map[*it] = it;

        return build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};

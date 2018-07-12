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
// pair
typedef pair<int, int> PII;
#define mp make_pair
#define fi first
#define se second

class Solution {
    vector<int> ans;

    void dfs(TreeNode* p) {
        if (!p)
            return;
        dfs(p->left);
        ans.push_back(p->val);
        dfs(p->right);
    }

    void nonDFS(TreeNode* p) {
        stack<pair<TreeNode*, int>> s;
        s.push(mp(p, 0));

        while (!s.empty()) {
            pair<TreeNode*, int> t = s.top();
            s.pop();
            if (!t.fi)
                continue;

            if (t.se == 0) {
                s.push(mp(t.fi, 1));
                s.push(mp(t.fi->left, 0));
            } else if (t.se == 1) {
                ans.push_back(t.fi->val);
                s.push(mp(t.fi->right, 0));
            }
        }
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        nonDFS(root);
        return ans;
    }
};

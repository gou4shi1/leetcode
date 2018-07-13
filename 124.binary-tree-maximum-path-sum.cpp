/*
 * [124] Binary Tree Maximum Path Sum
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (27.43%)
 * Total Accepted:    134.5K
 * Total Submissions: 488.6K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty binary tree, find the maximum path sum.
 * 
 * For this problem, a path is defined as any sequence of nodes from some
 * starting node to any node in the tree along the parent-child connections.
 * The path must contain at least one node and does not need to go through the
 * root.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * Output: 6
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-10,9,20,null,null,15,7]
 * 
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * Output: 42
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
    const int _INF = 0x80808080;

    PII dfs(TreeNode *p) {
        if (!p)
            return mp(_INF, _INF);

        int val = p->val;
        PII left = dfs(p->left);
        PII right = dfs(p->right);

        PII ans;
        ans.fi = max(left.fi, right.fi);
        ans.fi = max(ans.fi, val + max(left.se, 0) + max(right.se, 0));
        ans.se = val;
        ans.se = max(ans.se, left.se + val);
        ans.se = max(ans.se, right.se + val);
        return ans;
    }
        
public:
    int maxPathSum(TreeNode* root) {
        PII ans = dfs(root);
        return ans.fi;
    }
};

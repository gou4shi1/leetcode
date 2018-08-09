/*
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (35.99%)
 * Total Accepted:    116.3K
 * Total Submissions: 323.1K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 * 
 * Example: 
 * 
 * 
 * You may serialize the following tree:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 * 
 * as "[1,2,3,null,null,4,5]"
 * 
 * 
 * Clarification: The above format is the same as how LeetCode serializes a
 * binary tree. You do not necessarily need to follow this format, so please be
 * creative and come up with different approaches yourself.
 * 
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
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
#include <cstdlib>

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res("[");
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *p = q.front();
            q.pop();
            if (p != root)
                res += ",";
            res += p ? to_string(p->val) : "null";
            if (p) {
                q.push(p->left);
                q.push(p->right);
            }
        }
        res += "]";
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int len = data.length();
        char *ps = (char*)data.c_str();

        TreeNode *root = new TreeNode(0);
        queue<TreeNode**> q;
        q.push(&root);
        ++ps; // eat '['
        while (!q.empty() && *ps != ']') {
            TreeNode **pp = q.front();
            q.pop();
            if (*ps == ',')
                ++ps;

            if (*ps == 'n') {
                *pp = nullptr;
                ps += 4;
            } else {
                (*pp)->val = strtol(ps, &ps, 10);
                (*pp)->left = new TreeNode(0);
                (*pp)->right = new TreeNode(0);
                q.push(&(*pp)->left);
                q.push(&(*pp)->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

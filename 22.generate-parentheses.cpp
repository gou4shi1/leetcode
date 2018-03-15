/*
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (47.65%)
 * Total Accepted:    199.2K
 * Total Submissions: 417.8K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
// #include "header.h"

class Solution {
    int m = 0;
    string s;
    vector<string> v;

    void work(int k, int n1, int n2) {
        if (!n1 && !n2) {
            v.push_back(s);
            return;
        }

        if (n1 > 0) {
            s[k] = '(';
            work(k + 1, n1 - 1, n2);
        }
        if (n2 > n1) {
            s[k] = ')';
            work(k + 1, n1, n2 - 1);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        s.resize(2 * n);
        work(0, n, n);
        return v;
    }
};

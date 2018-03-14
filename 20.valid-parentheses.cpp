/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (33.94%)
 * Total Accepted:    310.2K
 * Total Submissions: 914.2K
 * Testcase Example:  '"["'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * The brackets must close in the correct order, "()" and "()[]{}" are all
 * valid but "(]" and "([)]" are not.
 * 
 */
// #include "header.h"

class Solution {
    char m[233];

public:
    bool isValid(string s) {
        m[')'] = '(';
        m[']'] = '[';
        m['}'] = '{';

        stack<int> st;
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else if (!st.empty() && m[s[i]] == st.top())
                st.pop();
            else
                return false;
        }
        return st.empty();
    }
};

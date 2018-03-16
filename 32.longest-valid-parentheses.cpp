/*
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (23.22%)
 * Total Accepted:    120.6K
 * Total Submissions: 519.4K
 * Testcase Example:  '""'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * 
 * For "(()", the longest valid parentheses substring is "()", which has length
 * = 2.
 * 
 * 
 * Another example is ")()())", where the longest valid parentheses substring
 * is "()()", which has length = 4.
 * 
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        stack<int> st;
        int be = -1, ans = 0;
        int f[len + 1];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < len; ++i) {
            if (s[i] == ')') {
                if (!st.empty()) {
                    be = st.top();
                    st.pop();
                    f[i + 1] = i - be + 1 + f[be];
                    ans = max(ans, f[i + 1]);
                }
            } else {
                st.push(i);
            }
        }
        return ans;
    }
};

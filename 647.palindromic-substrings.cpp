/*
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (54.41%)
 * Total Accepted:    48.7K
 * Total Submissions: 89.6K
 * Testcase Example:  '"abc"'
 *
 * 
 * Given a string, your task is to count how many palindromic substrings in
 * this string.
 * 
 * 
 * 
 * The substrings with different start indexes or end indexes are counted as
 * different substrings even they consist of same characters. 
 * 
 * 
 * Example 1:
 * 
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 
 * Note:
 * 
 * The input string length won't exceed 1000.
 * 
 * 
 */
class Solution {
    int ans = 0;

    void add(vector<int> &v, int x) {
        ++ans;
        v.push_back(x);
    }

public:
    int countSubstrings(string s) {
        int len = s.length();
        if (!len)
            return 0;
        
        vector<int> pre;
        add(pre, 0);
        for (int i = 1; i < len; ++i) {
            vector<int> curr;
            add(curr, i);
            if (s[i] == s[i - 1])
                add(curr, i - 1);
            for (int j: pre)
                if (j > 0 && s[j - 1] == s[i])
                    add(curr, j - 1);
            pre = curr;
        }

        return ans;
    }
};

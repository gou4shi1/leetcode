/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (24.65%)
 * Total Accepted:    450K
 * Total Submissions: 1.8M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * Examples:
 * 
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * 
 * Given "bbbbb", the answer is "b", with the length of 1.
 * 
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the
 * answer must be a substring, "pwke" is a subsequence and not a substring.
 */
// #include "header.h"
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if (!len)
            return 0;
        std::map<char, int> m;
        int ans = 1;
        m[s[0]] = 0;
        for (int i = 0, j = 1; j < len; ++j) {
            if (m.count(s[j]) && m[s[j]] >= 0) {
                int t =  m[s[j]];
                while (i <= t) {
                    m[s[i++]] = -1;
                }
            }
            m[s[j]] = j;
            ans = std::max(ans, j-i+1);
            if (ans == 3)
                std::cout << i << std::endl;
        }
        return ans;
    }
};

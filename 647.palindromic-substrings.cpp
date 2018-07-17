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
//#include "header.h"

class Solution {
    string conv(string &s) {
        string str("$#");
        for (char ch: s) {
            str += ch;
            str += '#';
        }
        return str;
    }

public:
    int countSubstrings(string s) {
        string str = conv(s);

        int ans = 0;
        vector<int> l(str.length() + 1);
        int center = 0, right = 0;
        for (int i = 1; i < (int)str.length(); ++i) {
            l[i] = 1;
            if (i < right)
                l[i] = min(l[2 * center - i], right - i);
            while (str[i - l[i]] == str[i + l[i]])
                ++l[i];
            if (i + l[i] > right) {
                right = i + l[i];
                center = i;
            }
            ans += l[i] / 2;
        }
        return ans;
    }
};

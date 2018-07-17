/*
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (42.17%)
 * Total Accepted:    59.7K
 * Total Submissions: 141.5K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * 
 * Given an encoded string, return it's decoded string.
 * 
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 * 
 * 
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 * 
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 * 
 * 
 * Examples:
 * 
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 * 
 * 
 */
//#include "header.h"

class Solution {
public:
    string decodeString(string s) {
        string digit("0123456789");
        string alpha;
        for (char ch = 'a'; ch <= 'z'; ++ch)
            alpha += ch;
        for (char ch = 'A'; ch <= 'Z'; ++ch)
            alpha += ch;

        vector<string> splited;
        for (size_t i = 0; i < s.length();) {
            if (isalpha(s[i])) {
                size_t j = s.find_first_not_of(alpha, i);
                if (j == string::npos)
                    j = s.length();
                splited.push_back(s.substr(i, j - i));
                i = j;
            } else if (isdigit(s[i])) {
                size_t j = s.find_first_not_of(digit, i);
                if (j == string::npos)
                    j = s.length();
                splited.push_back(s.substr(i, j - i));
                i = j;
            } else {
                splited.push_back(s.substr(i, 1));
                ++i;
            }
        }

        stack<string> st;
        for (string token: splited) {
            if (token[0] == ']') {
                string str;
                while (st.top()[0] != '[') {
                    str = st.top() + str; st.pop();
                }
                st.pop(); // [
                int k = stoi(st.top()); st.pop();
                string repeated;
                while (k--)
                    repeated += str;
                st.push(repeated);
            } else {
                st.push(token);
            }
        }

        string res;
        while (!st.empty()) {
            res = st.top() + res; st.pop();
        }
        return res;
    }
};

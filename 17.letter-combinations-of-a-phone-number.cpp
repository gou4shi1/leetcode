/*
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (36.25%)
 * Total Accepted:    221.6K
 * Total Submissions: 611.1K
 * Testcase Example:  '""'
 *
 * Given a digit string, return all possible letter combinations that the
 * number could represent.
 *
 *
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below.
 *
 *
 *
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 *
 *
 * Note:
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 *
 */
// #include "header.h"
class Solution {
    vector<string> ans;
    vector<string> m;
    int len;
    string t;

    void init_m() {
        m.push_back(string("hhh"));
        m.push_back(string("hhh"));
        m.push_back(string("abc"));
        m.push_back(string("def"));
        m.push_back(string("ghi"));
        m.push_back(string("jkl"));
        m.push_back(string("mno"));
        m.push_back(string("pqrs"));
        m.push_back(string("tuv"));
        m.push_back(string("wxyz"));
    }

    void work(int i, const string &digits) {
        if (i >= len) {
            if (t[0])
                ans.push_back(t);
            return;
        }

        int d = digits[i] - '0';
        for (int j = 0; j < m[d].length(); ++j) {
            t[i] = m[d][j];
            work(i + 1, digits);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
    len = digits.length();
    t.resize(len);
    init_m();
    work(0, digits);
    return ans;
    }
};

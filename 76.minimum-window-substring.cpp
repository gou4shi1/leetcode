/*
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (27.27%)
 * Total Accepted:    157.3K
 * Total Submissions: 574K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * 
 * 
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * 
 * Note:
 * 
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 * 
 * 
 */
//#include "header.h"
const int INF = 0x3f3f3f3f;
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty())
            return 0;
        int len = s.length();

        map<char, int> need, got;
        int need_num = 0, got_num = 0;
        for (char ch: t) {
            if (need[ch] == 0)
                ++need_num;
            ++need[ch];
        }

        int left = 0, min_left = 0, min_len = INF;
        map<char, int> cnt;

        for (int i = 0; i < len; ++i) {
            ++cnt[s[i]];
            if (need[s[i]] && !got[s[i]] && cnt[s[i]] >= need[s[i]]) {
                got[s[i]] = true;
                ++got_num;
            }

            while (left < i &&(!need[s[left]] || cnt[s[left]] > need[s[left]])) {
                --cnt[s[left]];
                ++left;
            }

            if (got_num == need_num && i - left + 1 < min_len) {
                min_len = i - left + 1;
                min_left = left;
            }
        }

        if (min_len == INF)
            min_len = 0;
        return s.substr(min_left, min_len);
    }
};

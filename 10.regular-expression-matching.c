/*
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (24.34%)
 * Total Accepted:    187.9K
 * Total Submissions: 771.7K
 * Testcase Example:  '"aa"\n"a"'
 *
 * Implement regular expression matching with support for '.' and '*'.
 * 
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 * 
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "a*") → true
 * isMatch("aa", ".*") → true
 * isMatch("ab", ".*") → true
 * isMatch("aab", "c*a*b") → true
 * 
 */
/*
#include <string.h>
#include <stdio.h>
#define true 1
#define false 0
#define bool int
*/
/* TLE:
bool isMatch(char* s, char* p) {
    int s_len = strlen(s), p_len = strlen(p);
    if (!s_len && !p_len)
        return true;
    if (!s_len) {
        while (p_len > 1 && p[1] == '*') {
            p += 2;
            p_len -= 2;
        }
        return p_len == 0;
    }
    if (!s_len || !p_len)
        return false;
    bool res = false;
    if (p_len > 1 && p[1] == '*') {
        res |= isMatch(s, p + 2);
        if (s[0] == p[0] || p[0] == '.') {
            res |= isMatch(s + 1, p + 2);
            res |= isMatch(s + 1, p);
        }
    } else if (s[0] == p[0] || p[0] == '.') {
        res |= isMatch(s + 1, p + 1);
    } else {
        return false;
    }
    return res;
}
*/
bool isMatch(char* s, char* p) {
    int s_len = strlen(s), p_len = strlen(p);
    bool f[p_len + 1][s_len + 1];
    memset(f, false, sizeof(f));
    f[0][0] = true;
    for (int i = 0; i < p_len; ++i) {
        if (i + 1 < p_len && p[i+1] == '*') {
            memcpy(f[i + 2], f[i], sizeof(f[0]));
            for (int j = 0; j < s_len; ++j) {
                if ((p[i] == s[j] || p[i] == '.') && f[i][j]) {
                    f[i][j + 1] = true;
                    f[i + 2][j + 1] = true;
                }
            }
            ++i;
        } else {
            for (int j = 0; j < s_len; ++j) {
                f[i + 1][j + 1] = (p[i] == s[j] || p[i] == '.') &&  f[i][j];
            }
        }
    }
    return f[p_len][s_len];
}
/*
int main() {
    puts(isMatch("aa", "aa") ? "y" : "n");
    return 0;
}
*/

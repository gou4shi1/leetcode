/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.20%)
 * Total Accepted:    293.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example:
 * 
 * 
 * Input: "babad"
 * 
 * Output: "bab"
 * 
 * Note: "aba" is also a valid answer.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "cbbd"
 * 
 * Output: "bb"
 * 
 * 
 * 
 * 
 */
/*
#include <string.h>
#include <stdlib.h>
*/
#define MIN(A,B) ({ __typeof__(A) __a = (A); __typeof__(B) __b = (B); __a < __b ? __a : __b; })

int p[6666];
char ss[6666];

char* longestPalindrome(char* s) {
    int len = strlen(s);
    for (int i = len; i >= 0; --i) {
        ss[i + i + 2] = s[i];
        ss[i + i + 1] = '#';
    }
    ss[0] = '*';

    int id = 0, maxlen = 0, maxi;
    for (int i = 2; i < 2 * len + 1; ++i) {
        p[i] = 1;
        if (p[id] + id > i) {
            p[i] = MIN(p[2 * id - i], p[id] + id - i);
        }
        while (ss[i - p[i]] == ss[i + p[i]]) {
            ++p[i];
        }

        if (id + p[id] < i + p[i]) {
            id = i;
        }
        if (maxlen < p[i]) {
            maxlen = p[i];
            maxi = i;
        }
    }

    maxi = maxi / 2 - 1;
    maxlen -= 1;
    if (maxlen % 2) {
        maxi -= maxlen / 2;
    } else {
        maxi -= (maxlen / 2) - 1;
    }
    /*puts(ss);*/
    /*printf("### %d %d\n", maxi, maxlen);*/
    s[maxi + maxlen] = '\0';
    return s + maxi;
}
/*
char s[666] = "babad";

int main() {
    printf("%s\n", longestPalindrome(s));
    return 0;
}*/

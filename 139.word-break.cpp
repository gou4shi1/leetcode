/*
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (31.88%)
 * Total Accepted:    226.2K
 * Total Submissions: 706.3K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 * 
 * 
 */
//#include "header.h"

class DictTree {
    DictTree *_child[26] = {nullptr};

    public:
    bool end = false;

    DictTree* child(char ch) {
        return _child[ch - 'a'] ? _child[ch - 'a'] : (_child[ch - 'a'] = new DictTree);
    }

    bool exist(char ch) {
        return _child[ch - 'a'];
    }

    void build(string &str) {
        DictTree *p = this;
        for (char ch: str) {
            p = p->child(ch);
        }
        p->end = true;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        vector<bool> dp;
        dp.resize(len + 1);

        DictTree *root = new DictTree;
        for (string &word: wordDict)
            root->build(word);

        dp[len] = true;
        for (int i = len - 1; i >= 0; --i) {
            DictTree *p = root;
            for (int j = i; j < len; ++j) {
                if (!p->exist(s[j]))
                    break;
                p = p->child(s[j]);
                if (p->end && dp[j + 1]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};

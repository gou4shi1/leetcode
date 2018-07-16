/*
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (32.15%)
 * Total Accepted:    121.4K
 * Total Submissions: 377.5K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * Example:
 * 
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");   
 * trie.search("app");     // returns true
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 * 
 * 
 */
//#include "header.h"

class TrieNode {
    TrieNode *_child[26] = {nullptr};

    public:
    bool end = false, contain = false;

    TrieNode* child(char ch) {
        return _child[ch - 'a'] ? _child[ch - 'a'] : (_child[ch - 'a'] = new TrieNode);
    }

    bool exist(char ch) {
        return _child[ch - 'a'];
    }
};

class Trie {
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for (char ch: word) {
            p->contain = true;
            p = p->child(ch);
        }
        p->end = p->contain = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;
        for (char ch: word) {
            if (!p->exist(ch))
                return false;
            p = p->child(ch);
        }
        return p->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (char ch: prefix) {
            if (!p->exist(ch))
                return false;
            p = p->child(ch);
        }
        return p->contain;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

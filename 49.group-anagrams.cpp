/*
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (39.53%)
 * Total Accepted:    214.7K
 * Total Submissions: 539.2K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * 
 * 
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note:
 * 
 * 
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * 
 * 
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> _map;
        vector<vector<string>> ans;
        int n = strs.size();

        for (string str: strs) {
            vector<char> str_spilited;
            for (char ch: str)
                str_spilited.push_back(ch);
            sort(str_spilited.begin(), str_spilited.end());
            string str_sorted;
            for (char ch: str_spilited)
                str_sorted += ch;
            _map[str_sorted].push_back(str);
        }

        for (auto p: _map) {
            ans.push_back(p.second);
        }
        return ans;
    }
};

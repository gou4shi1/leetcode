/*
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (38.61%)
 * Total Accepted:    149.5K
 * Total Submissions: 385.8K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 * 
 * Your algorithm should run in O(n) complexity.
 * 
 * Example:
 * 
 * 
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 */
//#include "header.h"

class Solution {
    int ans = 1;
    unordered_map<int, int> id;
    vector<int> fa, g;

    void _init(vector<int> &nums) {
        fa.resize(nums.size());
        g.resize(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            fa[i] = i;
            g[i] = 1;
            id[nums[i]] = i;
        }
    }

    int _find(int x) {
        if (fa[x] == x)
            return x;
        return fa[x] = _find(fa[x]);
    }

    void _union(int x, int y) {
        if (_find(x) == _find(y))
            return;
        g[_find(y)] += g[_find(x)];
        fa[_find(x)] = _find(y);
        ans = max(ans, g[_find(y)]);
    }

public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        _init(nums);

        for (int num: nums) {
            if (id[num - 1])
                _union(id[num], id[num - 1]);
            if (id[num + 1])
                _union(id[num], id[num + 1]);
        }

        return ans;
    }
};

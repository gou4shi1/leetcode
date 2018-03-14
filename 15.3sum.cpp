/*
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (21.79%)
 * Total Accepted:    303.6K
 * Total Submissions: 1.4M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array S of n integers, are there elements a, b, c in S such that a
 * + b + c = 0? Find all unique triplets in the array which gives the sum of
 * zero.
 * 
 * Note: The solution set must not contain duplicate triplets.
 * 
 * 
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */
//  #include "header.h"
class Solution {
    vector<vector<int>> ans;
    unordered_multiset<int> s;
    set<pair<int, int> > f;

    vector<int> make_triple(int a, int b, int c) {
        vector<int> ret;
        ret.push_back(a);
        ret.push_back(b);
        ret.push_back(c);
        return ret;
    }

    void try_ins(int a, int b) {
        if (f.count(make_pair(a, b)) > 0)
            return;
        int t = 0 - a - b;
        if (s.count(t) > 0) {
            f.insert(make_pair(a, b));
            ans.push_back(make_triple(a, b, t));
        }
    }

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();

        for (int i = 0; i < len; ++i)
            s.insert(nums[i]);

        if (s.count(0) >= 3)
            try_ins(0, 0);
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                int t = 0 - nums[i] - nums[j];
                if (nums[i] == 0) {
                    if (nums[j] > 0)
                        try_ins(0, nums[j]);
                } else if ((nums[i] > 0 && nums[j] > 0) || (nums[i] < 0 && nums[j] < 0)) {
                    try_ins(nums[i], nums[j]);
                }
            }
        }
        return ans;
    }
};

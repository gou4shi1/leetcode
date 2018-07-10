/*
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (45.90%)
 * Total Accepted:    252K
 * Total Submissions: 545K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
//#include "header.h"
class Solution {
    vector<vector<int>> ans;
    vector<int> subset;

    void dfs(vector<int>& nums, int k) {
        if (k == nums.size()) {
            ans.push_back(subset);
            return;
        }

        dfs(nums, k + 1);
        subset.push_back(nums[k]);
        dfs(nums, k + 1);
        subset.pop_back();
    }

    public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
};

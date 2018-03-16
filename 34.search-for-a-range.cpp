/*
 * [34] Search for a Range
 *
 * https://leetcode.com/problems/search-for-a-range/description/
 *
 * algorithms
 * Medium (31.60%)
 * Total Accepted:    181.3K
 * Total Submissions: 573.8K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers sorted in ascending order, find the starting and
 * ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 *
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 *
 */
// #include "header.h"

class Solution {
    vector<int> ans;

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        int l = 0, r = len - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] >= target)
                r = m;
            else
                l = m + 1;
        }
        if (len == 0 || nums[l] != target) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        } else {
            ans.push_back(l);
        }

        l = 0, r = len - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] > target)
                r = m;
            else
                l = m + 1;
        }
        if (nums[l] > target)
            ans.push_back(l - 1);
        else
            ans.push_back(len - 1);
        return ans;
    }
};

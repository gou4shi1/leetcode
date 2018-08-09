/*
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (39.11%)
 * Total Accepted:    142.7K
 * Total Submissions: 364.8K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 * 
 * Example:
 * 
 * 
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4 
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4. 
 * 
 * Note: 
 * 
 * 
 * There may be more than one LIS combination, it is only necessary for you to
 * return the length.
 * Your algorithm should run in O(n2) complexity.
 * 
 * 
 * Follow up: Could you improve it to O(n log n) time complexity?
 * 
 */

//#include "header.h"

class Solution {
    public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;

        vector<int> len(nums.size() + 1);
        len[1] = nums[0];
        int max_len = 1;

        for (int num: nums) {
            auto it = lower_bound(len.begin() + 1, len.begin() + 1 + max_len, num);
            if (it == len.begin() + 1 + max_len) {
                ++max_len;
                len[max_len] = num;
            } else if (*it > num) {
                *it = num;
            }
        }

        return max_len;
    }
};

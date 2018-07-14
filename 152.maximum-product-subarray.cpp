/*
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (27.00%)
 * Total Accepted:    148.8K
 * Total Submissions: 549K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 */
//#include "header.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int ret;
        vector<int> pre_min(nums.size()), pre_max(nums.size());
        ret = pre_min[0] = pre_max[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            pre_min[i] = min(nums[i], (nums[i] > 0 ? pre_min[i - 1] : pre_max[i - 1]) * nums[i]);
            pre_max[i] = max(nums[i], (nums[i] > 0 ? pre_max[i - 1] : pre_min[i - 1]) * nums[i]);
            ret = max(ret, pre_max[i]);
        }
        return ret;
    }
};

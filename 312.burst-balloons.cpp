/*
 * [312] Burst Balloons
 *
 * https://leetcode.com/problems/burst-balloons/description/
 *
 * algorithms
 * Hard (44.22%)
 * Total Accepted:    43.7K
 * Total Submissions: 98.7K
 * Testcase Example:  '[3,1,5,8]'
 *
 * Given n balloons, indexed from 0 to n-1. Each balloon is painted with a
 * number on it represented by array nums. You are asked to burst all the
 * balloons. If the you burst balloon i you will get nums[left] * nums[i] *
 * nums[right] coins. Here left and right are adjacent indices of i. After the
 * burst, the left and right then becomes adjacent.
 * 
 * Find the maximum coins you can collect by bursting the balloons wisely.
 * 
 * Note:
 * 
 * 
 * You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can
 * not burst them.
 * 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
 * 
 * 
 * Example:
 * 
 * 
 * Input: [3,1,5,8]
 * Output: 167 
 * Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  -->
 * []
 * coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
 * 
 * 
 */
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(nums.size());
        for (vector<int> &v: dp)
            v.resize(nums.size());

        for (int l = 1; l <= n; ++l) {
            for (int i = 1; i + l - 1 <= n; ++i) {
                int ii = i + l - 1;
                for (int j = i; j <= ii; ++j)
                    dp[i][ii] = max(dp[i][ii], (i < j ? dp[i][j - 1] : 0) + nums[i - 1] * nums[j] * nums[ii + 1] + (j < ii ? dp[j + 1][ii] : 0));
            }
        }
        return dp[1][n];
    }
};

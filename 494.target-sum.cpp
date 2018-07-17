/*
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (43.94%)
 * Total Accepted:    58.7K
 * Total Submissions: 133.7K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 
 * You are given a list of non-negative integers, a1, a2, ..., an, and a
 * target, S. Now you have 2 symbols + and -. For each integer, you should
 * choose one from + and - as its new symbol.
 * ⁠
 * 
 * Find out how many ways to assign symbols to make sum of integers equal to
 * target S.  
 * 
 * 
 * Example 1:
 * 
 * Input: nums is [1, 1, 1, 1, 1], S is 3. 
 * Output: 5
 * Explanation: 
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 * 
 * 
 * 
 * Note:
 * 
 * The length of the given array is positive and will not exceed 20. 
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
 * 
 * 
 */
class Solution {
    int dfs(vector<int> &nums, vector<int>::iterator beg, int sum, int target) {
        if (beg == nums.end()) {
            if (sum == target)
                return 1;
            return 0;
        }

        return dfs(nums, beg + 1, sum + *beg, target) + dfs(nums, beg + 1, sum - *beg, target);
    }

public:
    int findTargetSumWays(vector<int>& nums, int S) {
        map<int, int> pre;
        pre[0] = 1;
        for (int num: nums) {
            map<int, int> curr;
            for (auto p: pre) {
                curr[p.first + num] += p.second;
                curr[p.first - num] += p.second;
            }
            pre = curr;
        }

        return pre[S];
    }
};

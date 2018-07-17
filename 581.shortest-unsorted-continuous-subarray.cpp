/*
 * [581] Shortest Unsorted Continuous Subarray
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (29.38%)
 * Total Accepted:    40K
 * Total Submissions: 136.2K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * Given an integer array, you need to find one continuous subarray that if you
 * only sort this subarray in ascending order, then the whole array will be
 * sorted in ascending order, too.  
 * 
 * You need to find the shortest such subarray and output its length.
 * 
 * Example 1:
 * 
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make
 * the whole array sorted in ascending order.
 * 
 * 
 * 
 * Note:
 * 
 * Then length of the input array is in range [1, 10,000].
 * The input array may contain duplicates, so ascending order here means . 
 * 
 * 
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.empty())
            return 0;

        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());

        int i = 0;
        while (i < nums.size() && nums[i] == sorted[i])
            ++i;
        if (i == nums.size())
            return 0;
        int j = nums.size() - 1;
        while (j && nums[j] == sorted[j])
            --j;
        return j - i + 1;
    }
};

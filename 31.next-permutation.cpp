/*
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (29.01%)
 * Total Accepted:    144.5K
 * Total Submissions: 498.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * 
 * The replacement must be in-place, do not allocate extra memory.
 * 
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        for (int i = len - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                int m = i + 1;
                for (int j = i + 1; j < len; ++j)
                    if (nums[j] > nums[i] && nums[j] < nums[m])
                            m = j;
                 swap(nums[i], nums[m]);
                 sort(nums.begin() + i + 1, nums.end());
                 return;
            }
        }
        sort(nums.begin(), nums.end());
    }
};

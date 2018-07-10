/*
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (39.31%)
 * Total Accepted:    233.8K
 * Total Submissions: 593K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array with n objects colored red, white or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order
 * red, white and blue.
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 * 
 * Note: You are not suppose to use the library's sort function for this
 * problem.
 * 
 * Example:
 * 
 * 
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * 
 * Follow up:
 * 
 * 
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with a one-pass algorithm using only constant space?
 * 
 * 
 */
//#include "header.h"
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return;

        int end0 = 0, end1 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                swap(nums[end1++], nums[i]);
            } else if (nums[i] == 0) {
                swap(nums[end0++], nums[i]);
                if (end1 < end0) {
                    end1 = end0;
                } else {
                    swap(nums[end1++], nums[i]);
                }
            }
        }
    }
};

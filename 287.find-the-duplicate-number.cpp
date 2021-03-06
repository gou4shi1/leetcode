/*
 * [287] Find the Duplicate Number
 *
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (45.20%)
 * Total Accepted:    119.1K
 * Total Submissions: 263.4K
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * Given an array nums containing n + 1 integers where each integer is between
 * 1 and n (inclusive), prove that at least one duplicate number must exist.
 * Assume that there is only one duplicate number, find the duplicate one.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,4,2,2]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,1,3,4,2]
 * Output: 3
 * 
 * Note:
 * 
 * 
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n2).
 * There is only one duplicate number in the array, but it could be repeated
 * more than once.
 * 
 * 
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sp = nums[0], fp = nums[0];
        do {
            sp = nums[sp];
            fp = nums[nums[fp]];
        } while (sp != fp);

        fp = nums[0];
        while (fp != sp) {
            fp = nums[fp];
            sp = nums[sp];
        }
        return fp;
    }
};

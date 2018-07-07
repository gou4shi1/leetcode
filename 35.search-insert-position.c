/*
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (40.04%)
 * Total Accepted:    273K
 * Total Submissions: 681.9K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5,6], 5
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,3,5,6], 2
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,3,5,6], 7
 * Output: 4
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [1,3,5,6], 0
 * Output: 0
 * 
 * 
 */
int searchInsert(int* nums, int numsSize, int target) {
    if (numsSize == 0)
        return 0;

    if (target < nums[0])
        return 0;

    for (int i = 0; i < numsSize - 1; ++i) {
        if (nums[i] == target)
            return i;
        if (nums[i] < target && nums[i + 1] > target)
            return i + 1;
    }

    if (target == nums[numsSize - 1])
        return numsSize - 1;

    if (target > nums[numsSize - 1])
        return numsSize;
    return -1;
}

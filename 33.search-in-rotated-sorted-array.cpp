/*
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (31.95%)
 * Total Accepted:    242.2K
 * Total Submissions: 758.4K
 * Testcase Example:  '[]\n5'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
       int len = nums.size();
       if (!len)
           return -1;
       int k = -1;
       for (int i = 1; i < len; ++i)
           if (nums[i] < nums[i - 1]) {
               k = i;
               break;
           }
       int l = 0, r = k - 1;
       if (k == -1)
           r = len - 1;
       while (l < r) {
           int m = (l + r) / 2;
           if (target == nums[m]) {
               return m;
           } else if (target < nums[m]) {
               r = m - 1;
           } else {
               l = m + 1;
           }
       }
       if (target == nums[l])
           return l;
       if (k == -1)
           return -1;
       l = k, r = len - 1;
       while (l < r) {
           int m = (l + r) / 2;
           if (target == nums[m]) {
               return m;
           } else if (target < nums[m]) {
               r = m - 1;
           } else {
               l = m + 1;
           }
       }
       if (target == nums[l])
           return l;
       return -1;
    }
};

/*
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (41.72%)
 * Total Accepted:    229.5K
 * Total Submissions: 550K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */
//#include "header.h"

class Solution {
    int partition(vector<int>::iterator bg, vector<int>::iterator ed) {
        int pivot = *(ed - 1);
        auto i = bg;
        for (auto j = bg; j < ed; ++j) {
            if (*j > pivot) {
                swap(*i, *j);
                ++i;
            }
        }
        swap(*i, *(ed - 1));
        return i - bg;
    }

    int kth(vector<int>::iterator bg, vector<int>::iterator ed, int k) {
        int p = partition(bg, ed);
        if (k == p + 1)
            return *(bg + p);
        if (k < p + 1)
            return kth(bg, bg + p, k);
        if (k > p + 1)
            return kth(bg + p + 1, ed, k - p - 1);
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        return kth(nums.begin(), nums.end(), k);
    }
};

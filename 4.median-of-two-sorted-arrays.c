/*
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (22.88%)
 * Total Accepted:    240K
 * Total Submissions: 1M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * Example 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * 
 * Example 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
int bs(int x, int *nums, int numsSize) {
    int l = 0, r = numsSize - 1;
    while (l < r) {
        int m  = (l + r) / 2;
        if (nums[m] < x) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    if (nums[l] >= x) {
        return l;
    } else {
        return numsSize;
    }
}

double nth(int n, int *nums1, int nums1Size, int *nums2, int nums2Size) {
    /*printf("## %d %d %d\n", n, nums1Size, nums2Size);*/
    if (!nums1Size) {
        return nums2[n - 1];
    } else if (!nums2Size) {
        return nums1[n - 1];
    }

    int i = nums1Size / 2;
    int j = bs(nums1[i], nums2, nums2Size);
    int k = i + 1 + j;
    if (n == k) {
        return nums1[i];
    } else if (n < k) {
        return nth(n, nums1, i, nums2, j);
    } else {
        return nth(n - k, nums1 + i + 1, nums1Size - i - 1, nums2 + j, nums2Size - j);
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if ((nums1Size+nums2Size) % 2) {
        return nth((nums1Size + nums2Size) / 2 + 1, nums1, nums1Size, nums2, nums2Size);
    } else {
        return (nth((nums1Size + nums2Size) / 2, nums1, nums1Size, nums2, nums2Size) + nth((nums1Size + nums2Size) / 2 + 1, nums1, nums1Size, nums2, nums2Size)) / 2;
    }
}
/*
int main() {
    int nums1[2] = {1, 3};
    int nums1Size = 2;
    int nums2[1] = {2};
    int nums2Size = 1;
    printf("%f\n", findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));
    return 0;
}*/

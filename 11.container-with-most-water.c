/*
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (37.07%)
 * Total Accepted:    186.7K
 * Total Submissions: 503.7K
 * Testcase Example:  '[1,1]'
 *
 * Given n non-negative integers a1, a2, ..., an, where each represents a point
 * at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 */

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int maxArea(int* height, int heightSize) {
    int ret = 0;
    int l = 0, r = heightSize - 1;
    while (l < r) {
        ret = max(ret, (r - l) * min(height[l], height[r]));
        if (height[l] < height[r])
            ++l;
        else
            --r;
    }
    return ret;
}

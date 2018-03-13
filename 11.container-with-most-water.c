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
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int work(int *height, int heightSize) {
    int ret = 0;
    for (int i = 1; i < heightSize; ++i) {
        for (int j = 0; j < i; ++j) {
            if (height[j] >= height[i]) {
                ret = MAX(ret, (i - j) * height[i]);
                break;
            }
        }
    }
    return ret;
}

int maxArea(int* height, int heightSize) {
    int height_rev[heightSize];
    for (int i = 0; i < heightSize; ++i)
        height_rev[heightSize - i - 1] = height[i];
    return MAX(work(height, heightSize), work(height_rev, heightSize));
}
/*
int main() {
    int arr[] = {2,3,10,5,7,8,9};
    printf("%d\n", maxArea(arr, 7));
    return 0;
}
*/

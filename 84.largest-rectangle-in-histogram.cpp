/*
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (27.96%)
 * Total Accepted:    124.7K
 * Total Submissions: 443.9K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [2,1,5,6,2,3]
 * Output: 10
 * 
 * 
 */
//#include "header.h"
// pair
typedef pair<int, int> PII;
#define mp make_pair
#define fi first
#define se second

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> l;
        l.resize(n);
        deque<PII> mono_queue;
        mono_queue.push_back(mp(-1, -1));
        for (int i = 0; i < n; ++i) {
            while (mono_queue.back().fi >= heights[i])
                mono_queue.pop_back();
            l[i] = mono_queue.back().se + 1;
            mono_queue.push_back(mp(heights[i], i));
        }

        vector<int> r;
        r.resize(n);
        mono_queue.clear();
        mono_queue.push_back(mp(-1, n));
        for (int i = n - 1; i >= 0; --i) {
            while (mono_queue.back().fi >= heights[i])
                mono_queue.pop_back();
            r[i] = mono_queue.back().se;
            mono_queue.push_back(mp(heights[i], i));
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (r[i] - l[i]) * heights[i]);
        }
        return ans;
    }
};

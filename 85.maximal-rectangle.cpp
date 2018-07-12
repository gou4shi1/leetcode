/*
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (30.07%)
 * Total Accepted:    90.6K
 * Total Submissions: 299.9K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * Output: 6
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

    public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row_size = matrix.size();
        if (row_size == 0)
            return 0;
        int col_size = matrix[0].size();

        int ans = 0;
        vector<int> last;
        last.resize(col_size);

        for (int i = 0; i < row_size; ++i) {
            for (int j = 0; j < col_size; ++j) {
                last[j] = matrix[i][j] == '1' ? (last[j] + 1) : 0;
            }
            ans = max(ans, largestRectangleArea(last));
        }

        return ans;
    }
};

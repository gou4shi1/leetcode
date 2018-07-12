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
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row_size = matrix.size();
        if (row_size == 0)
            return 0;
        int col_size = matrix[0].size();

        vector<vector<int>> last;
        last.resize(row_size + 1);
        for (vector<int>& row: last)
            row.resize(col_size + 1);

        int ans = 0;
        for (int j = 1; j <= col_size; ++j) {
            for (int i = 1; i <= row_size; ++i) {
                last[i][j] = matrix[i - 1][j - 1] == '1' ? (last[i][j - 1] + 1) : 0;
                int min_last = last[i][j];
                for (int k = i; k >= 1; --k) {
                    min_last = min(min_last, last[k][j]);
                    ans = max(ans, min_last * (i - k + 1));
                }
            }
        }

        return ans;
    }
};

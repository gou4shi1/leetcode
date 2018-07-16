/*
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (30.78%)
 * Total Accepted:    93.9K
 * Total Submissions: 305.1K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Output: 4
 * 
 * 
 */
//#include "header.h"

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;

        int row_size = matrix.size();
        int col_size = matrix[0].size();
        vector<vector<int>> f(row_size + 1), l_up(row_size + 1), l_left(row_size + 1);
        for (vector<int> &row: f)
            row.resize(col_size + 1);
        for (vector<int> &row: l_up)
            row.resize(col_size + 1);
        for (vector<int> &row: l_left)
            row.resize(col_size + 1);

        int ans = 0;
        for (int i = 1; i <= row_size; ++i) {
            for (int j = 1; j <= col_size; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    l_up[i][j] = l_up[i - 1][j] + 1;
                    l_left[i][j] = l_left[i][j - 1] + 1;
                    f[i][j] = min(f[i - 1][j - 1] + 1, min(l_up[i][j], l_left[i][j]));
                    ans = max(ans, f[i][j]);
                }
            }
        }
        return ans * ans;
    }
};

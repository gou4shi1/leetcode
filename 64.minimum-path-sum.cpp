/*
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (41.59%)
 * Total Accepted:    159.7K
 * Total Submissions: 381.8K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * 
 * 
 */
//#include "header.h"
class Solution {
    int row_size, col_size;
    vector<vector<int>> dp;

public:
    int minPathSum(vector<vector<int>>& grid) {
        row_size = grid.size();
        if (row_size == 0)
            return 0;
        col_size = grid[0].size();
        dp.resize(row_size + 1);
        for (vector<int>& row: dp)
            row.resize(col_size + 1);

        for (int i = row_size - 1; i >= 0; --i) {
            for (int j = col_size - 1; j >= 0; --j) {
                dp[i][j] = grid[i][j];
                if (i == row_size - 1 && j != col_size - 1) {
                    dp[i][j] += dp[i][j + 1];
                } else if (i != row_size - 1 && j == col_size - 1) {
                    dp[i][j] += dp[i + 1][j];
                } else {
                    dp[i][j] += min(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};

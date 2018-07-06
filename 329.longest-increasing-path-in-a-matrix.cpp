/*
 * [329] Longest Increasing Path in a Matrix
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (37.59%)
 * Total Accepted:    55.5K
 * Total Submissions: 147.7K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * Given an integer matrix, find the length of the longest increasing path.
 * 
 * From each cell, you can either move to four directions: left, right, up or
 * down. You may NOT move diagonally or move outside of the boundary (i.e.
 * wrap-around is not allowed).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = 
 * [
 * ⁠ [9,9,4],
 * ⁠ [6,6,8],
 * ⁠ [2,1,1]
 * ] 
 * Output: 4 
 * Explanation: The longest increasing path is [1, 2, 6, 9].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = 
 * [
 * ⁠ [3,4,5],
 * ⁠ [3,2,6],
 * ⁠ [2,2,1]
 * ] 
 * Output: 4 
 * Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally
 * is not allowed.
 * 
 * 
 */
#define mp make_pair
#define fi first
#define se second

class Solution {
    typedef pair<int, pair<int, int> > TRI;

    const int dr[4] = {0, -1, 0, 1};
    const int dc[4] = {-1, 0, 1, 0};

public:
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        int row_size = matrix.size();
        if (row_size == 0)
            return 0;
        int col_size = matrix[0].size();

        vector<TRI> all_ele;
        for (int i = 0; i < row_size; ++i) {
            for (int j = 0; j < col_size; ++j) {
                all_ele.push_back(mp(matrix[i][j], mp(i, j)));
            }
        }
        sort(all_ele.begin(), all_ele.end());

        vector<vector<int>> dp;
        dp.resize(row_size);
        for (int i = 0; i < row_size; ++i)
            dp[i].resize(col_size);

        int max_length = 0;
        for (auto it = all_ele.rbegin(); it != all_ele.rend(); ++it) {
            int r = it->se.fi, c = it->se.se;
            dp[r][c] = 1;
            for (int i = 0; i < 4; ++i) {
                int rr = r + dr[i], cc = c + dc[i];
                if (rr < 0 || rr >= row_size || cc < 0 || cc >= col_size)
                    continue;
                if (matrix[r][c] < matrix[rr][cc]) {
                    dp[r][c] = max(dp[r][c], dp[rr][cc] + 1);
                }
            }
            max_length = max(max_length, dp[r][c]);
        }

        return max_length;
    }
};

/*
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (37.34%)
 * Total Accepted:    192.8K
 * Total Submissions: 516.2K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 * 
 */
//#include "header.h"

class Solution {
    int row_size, col_size;
    vector<vector<bool>> visited;

    const int dr[4] = {0, -1, 0, 1};
    const int dc[4] = {-1, 0, 1, 0};

    void dfs(vector<vector<char>> &grid, int r, int c) {
        if (r < 0 || c < 0 || r >= row_size || c >= col_size)
            return;

        if (grid[r][c] == '0' || visited[r][c])
            return;
        visited[r][c] = true;

        for (int i = 0; i < 4; ++i) {
            int rr = r + dr[i];
            int cc = c + dc[i];
            dfs(grid, rr, cc);
        }
    }

    public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;

        row_size = grid.size();
        col_size = grid[0].size();
        visited.resize(row_size);
        for (vector<bool>& row: visited)
            row.resize(col_size);

        int ans = 0;
        for (int i = 0; i < row_size; ++i) {
            for (int j = 0; j < col_size; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ++ans;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};

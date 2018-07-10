/*
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (28.41%)
 * Total Accepted:    188.9K
 * Total Submissions: 663.5K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */
//#include "header.h"
class Solution {
    string _word;
    int _len;
    int row_size, col_size;
    vector<vector<bool>> visited;

    const int dr[4] = {0, -1, 0, 1};
    const int dc[4] = {-1, 0, 1, 0};

    bool dfs(vector<vector<char>>& board, int r, int c, int k) {
        if (r < 0 || c < 0 || r >= row_size || c >= col_size)
            return false;

        if (visited[r][c])
            return false;

        if (board[r][c] != _word[k])
            return false;
        if (k == _len - 1)
            return true;

        visited[r][c] = true;
        for (int i = 0; i < 4; ++i) {
            int rr = r + dr[i];
            int cc = c + dc[i];
            if (dfs(board, rr, cc, k + 1))
                return true;
        }
        visited[r][c] = false;

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        _word = word;
        _len = word.length();

        row_size = board.size();
        if (row_size == 0)
            return false;
        col_size = board[0].size();
        visited.resize(row_size);
        for (vector<bool>& row: visited)
            row.resize(col_size);

        for (int i = 0; i < row_size; ++i) {
            for (int j = 0; j < col_size; ++j) {
                if (dfs(board, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};

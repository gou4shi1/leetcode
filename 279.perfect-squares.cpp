/*
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (38.39%)
 * Total Accepted:    122.4K
 * Total Submissions: 318.9K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 * 
 * Example 1:
 * 
 * 
 * Input: n = 12
 * Output: 3 
 * Explanation: 12 = 4 + 4 + 4.
 * 
 * Example 2:
 * 
 * 
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 * 
 */
class Solution {
    vector<int> dp;

    void pre_cal(int n) {
        dp.resize(n + 1, -1);
        dp[0] = 0;
        for (int i = 1; i * i <= n; ++i) {
            int ii = i * i;
            for (int j = ii; j <= n; ++j) {
                if (dp[j] == -1 || (dp[j - ii] != -1 && dp[j - ii] + 1 < dp[j]))
                    dp[j] = dp[j - ii] + 1;
            }
        }
    }

public:
    int numSquares(int n) {
        pre_cal(n);
        return dp[n];
    }
};

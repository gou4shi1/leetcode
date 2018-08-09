/*
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (42.52%)
 * Total Accepted:    68K
 * Total Submissions: 159.9K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (ie, buy one and sell one share of the stock
 * multiple times) with the following restrictions:
 * 
 * 
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1
 * day)
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,0,2]
 * Output: 3 
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 * 
 * 
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;

        vector<int> dp(prices.size()), pre_dp(prices.size());
        for (int i = 1; i < prices.size(); ++i) {
            dp[i] = prices[i] - prices[0];
            for (int j = 1; j < i; ++j)
                dp[i] = max(dp[i], ((j - 2 >= 0) ? pre_dp[j - 2] : 0) + prices[i] - prices[j]);
            pre_dp[i] = max(pre_dp[i - 1], dp[i]);
        }
        return pre_dp[prices.size() - 1];
    }
};

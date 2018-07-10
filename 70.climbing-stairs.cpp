/*
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (41.61%)
 * Total Accepted:    266.5K
 * Total Submissions: 639.4K
 * Testcase Example:  '2'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 * 
 * Note: Given n will be a positive integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 * 
 * 
 */
//#include "header.h"
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;

        int f_n = 2, f_n_1 = 1, f_n_2 = 1;
        for (int i = 3; i <= n; ++i) {
            f_n_2 = f_n_1;
            f_n_1 = f_n;
            f_n = f_n_1 + f_n_2;
        }

        return f_n;
    }
};

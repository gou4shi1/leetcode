/*
 * [400] Nth Digit
 *
 * https://leetcode.com/problems/nth-digit/description/
 *
 * algorithms
 * Easy (30.03%)
 * Total Accepted:    37.2K
 * Total Submissions: 124.1K
 * Testcase Example:  '3'
 *
 * Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8,
 * 9, 10, 11, ... 
 * 
 * Note:
 * n is positive and will fit within the range of a 32-bit signed integer (n <
 * 231).
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 3
 * 
 * Output:
 * 3
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * 11
 * 
 * Output:
 * 0
 * 
 * Explanation:
 * The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a
 * 0, which is part of the number 10.
 * 
 * 
 */
//#include "header.h"

class Solution {
public:
    int findNthDigit(long long n) {
        long long len = 1, pro = 1;
        while (9 * len * pro < n) {
            n -= 9 * len * pro;
            ++len;
            pro *= 10;
        }

        int m = n / len;
        if (n % len == 0)
            --m;
        n -= len * m;

        int num = pro + m;
        int t = len - n;
        while (t--)
            num /= 10;
        return num % 10;
    }
};

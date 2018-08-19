/*
 * [440] K-th Smallest in Lexicographical Order
 *
 * https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/
 *
 * algorithms
 * Hard (25.78%)
 * Total Accepted:    6.6K
 * Total Submissions: 25.6K
 * Testcase Example:  '13\n2'
 *
 * Given integers n and k, find the lexicographically k-th smallest integer in
 * the range from 1 to n.
 * 
 * Note: 1 ≤ k ≤ n ≤ 109.
 * 
 * Example:
 * 
 * Input:
 * n: 13   k: 2
 * 
 * Output:
 * 10
 * 
 * Explanation:
 * The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so
 * the second smallest number is 10.
 * 
 * 
 * 
 */
typedef long long LL;

class Solution {
public:
    int findKthNumber(int n, int k) {
        int prefix = 1;
        while (--k) {
            // calculate #|{prefix*, prefix**, prefix***, ...}|
            int cnt = -1;
            for (LL l = prefix, r = l + 1; l <= n; l *= 10, r *= 10) {
                cnt += min(n + 1LL, r) - l;
            }
            
            if (k > cnt) {   
                ++prefix;
                k -= cnt;
            } else {   
                prefix *= 10;
            }
        }
        return prefix;
    }
};

/*
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (50.27%)
 * Total Accepted:    116.3K
 * Total Submissions: 231.3K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * For example,
 * Given [1,1,1,2,2,3] and k = 2, return [1,2].
 * 
 * 
 * Note: 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * 
 */
//#include "header.h"

// pair
typedef pair<int, int> PII;
#define mp make_pair
#define fi first
#define se second

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> _map;
        for (int num: nums)
            ++_map[num];

        vector<PII> flatten(_map.begin(), _map.end());
        nth_element(flatten.begin(), flatten.begin() + k, flatten.end(), [] (const PII &l, const PII &r) {
                return l.se > r.se;
                });

        vector<int> res(k);
        for (int i = 0; i < k; ++i)
            res[i] = flatten[i].first;
        return res;
    }
};

/*
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (37.58%)
 * Total Accepted:    831.6K
 * Total Submissions: 2.2M
 * Testcase Example:  '[3,2,4]\n6'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 *
 * Example:
 *
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 *
 *
 */
class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        std::unordered_map<int, int> m;
        int n = nums.size();
        for (int i = 0; i != n; ++i) {
            m[nums[i]] = i;
        }
        for (int i = 0; i != n; ++i) {
            if (m.count(target-nums[i]) != 0) {
                if (i == m[target-nums[i]])
                    continue;
                vector<int> v;
                v.push_back(i);
                v.push_back(m[target-nums[i]]);
                return v;
            }
        }
    }
};

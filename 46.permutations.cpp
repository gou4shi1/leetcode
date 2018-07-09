/*
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (48.34%)
 * Total Accepted:    252.5K
 * Total Submissions: 519.6K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
//#include "header.h"
class Solution {
    vector<vector<int>> ans;
    vector<int> permutation;
    unordered_map<int, bool> choosen;
    int n;

    void dfs(vector<int>& nums) {
        if (permutation.size() == n) {
            ans.push_back(permutation);
            return;
        }

        for (int x: nums) {
            if (choosen[x])
                continue;
            permutation.push_back(x);
            choosen[x] = true;
            dfs(nums);
            choosen[x] = false;
            permutation.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();

        dfs(nums);

        return ans;
    }
};

/*
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (42.24%)
 * Total Accepted:    231.9K
 * Total Submissions: 546.5K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */
class Solution {
  int _size;
  int _target;
  vector<int> _choosen;
  vector<vector<int>> _ans;

  void dfs(vector<int>& candidates, int start, int sum) {
    if (sum > _target)
      return;
    if (sum == _target) {
      _ans.push_back(_choosen);
    }
    
    for (int i = start; i < _size; ++i) {
      _choosen.push_back(candidates[i]);
      dfs(candidates, i, sum + candidates[i]);
      _choosen.pop_back();
    }
  }

  public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    _size = candidates.size();
    _target = target;
    _choosen.reserve(_size);

    sort(candidates.begin(), candidates.end());
    dfs(candidates, 0, 0);

    return _ans;
  }
};


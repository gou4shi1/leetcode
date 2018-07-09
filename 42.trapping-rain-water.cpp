/*
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (38.13%)
 * Total Accepted:    179.3K
 * Total Submissions: 468K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 */
// pair
typedef pair<int, int> PII;
#define mp make_pair
#define fi first
#define se second

class Solution {
    public:
        int trap(vector<int>& height) {
            int size = height.size();
            if (size <= 2) {
                return 0;
            }

            int ans = 0;
            deque<PII> q;
            q.push_front(mp(height[0], 1));
            for (int i = 1; i < size; ++i) {
                if (height[i] == q.back().fi) {
                    ++q.back().se;
                } else if (height[i] < q.back().fi) {
                    q.push_back(mp(height[i], 1));
                } else {
                    while (height[i] > q.back().fi) {
                        PII last = q.back();
                        q.pop_back();
                        if (q.empty()) {
                            q.push_back(mp(height[i], 1));
                            break;
                        }
                        if (height[i] > q.back().fi) {
                            ans += (q.back().fi - last.fi) * last.se;
                            q.back().se += last.se;
                        } else {
                            ans += (height[i] - last.fi) * last.se;
                            q.push_back(mp(height[i], last.se + 1));
                            break;
                        }
                    }
                }
            }
            return ans;
        }
};

/*
 * [587] Erect the Fence
 *
 * https://leetcode.com/problems/erect-the-fence/description/
 *
 * algorithms
 * Hard (33.67%)
 * Total Accepted:    4.9K
 * Total Submissions: 14.5K
 * Testcase Example:  '[[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]'
 *
 * There are some trees, where each tree is represented by (x,y) coordinate in
 * a two-dimensional garden. Your job is to fence the entire garden using the
 * minimum length of rope as it is expensive. The garden is well fenced only if
 * all the trees are enclosed. Your task is to help find the coordinates of
 * trees which are exactly located on the fence perimeter.
 * 
 * Example 1:
 * 
 * Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
 * Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
 * Explanation:
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [[1,2],[2,2],[4,2]]
 * Output: [[1,2],[2,2],[4,2]]
 * Explanation:
 * 
 * Even you only have trees in a line, you need to use rope to enclose
 * them. 
 * 
 * 
 * 
 * ⁠Note: 
 * 
 * All trees should be enclosed together. You cannot cut the rope to enclose
 * trees that will separate them in more than one group.
 * All input integers will range from 0 to 100. 
 * The garden has at least one tree. 
 * All coordinates are distinct. 
 * Input points have NO order. No order required for output.
 * 
 * 
 */
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
  //#include "header.h"

double eps = 1e-8;

int sgn(double x) {
  return x < -eps ? -1 : (x > eps ? 1 : 0);
}

Point operator - (const Point &a, const Point &b) {
  return Point(a.x - b.x, a.y - b.y);
}

bool operator < (const Point &a, const Point &b) {
  return sgn(a.x - b.x) < 0 || (sgn(a.x - b.x) == 0 && sgn(a.y - b.y) < 0);
}

bool operator == (const Point &a, const Point &b) {
  return sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0;
}

class Solution {

  double cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
  }

  public:
  vector<Point> outerTrees(vector<Point>& points) {
    vector<Point> res;
    res.resize(2 * points.size() + 5);
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());
    int m = 0, len = points.size();
    for (int i = 0; i < len; ++i) {
      while (m > 1 && sgn(cross(res[m - 1] - res[m - 2], points[i] - res[m - 2])) < 0)
        --m;
      res[m++] = points[i];
    }
    int k = m;
    for (int i = len - 2; i >= 0; --i) {
      while (m > k && sgn(cross(res[m - 1] - res[m - 2], points[i] - res[m - 2])) < 0)
        --m;
      res[m++] = points[i];
    }
    res.resize(m);
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    //if (len > 1)
      //res.resize(m - 1);
    return res;
  }
};

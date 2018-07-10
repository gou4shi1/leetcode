/*
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (32.39%)
 * Total Accepted:    214.1K
 * Total Submissions: 658.9K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
 * 
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() < 2) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end(), [] (const Interval &lhs, const Interval &rhs) {
                return (lhs.start != rhs.start) ? (lhs.start < rhs.start) : (lhs.end < rhs.end);
                });

        vector<Interval> ans;
        int start = intervals[0].start, end = intervals[0].end;
        for (Interval interval: intervals) {
            if (interval.start > end) {
                ans.push_back(Interval(start, end));
                start = interval.start;
                end = interval.end;
                continue;
            }

            end = max(end, interval.end);
        }
        ans.push_back(Interval(start, end));

        return ans;
    }
};

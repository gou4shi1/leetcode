/*
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (34.32%)
 * Total Accepted:    134.7K
 * Total Submissions: 392.5K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * Example 1:
 * 
 * 
 * Input: 2, [[1,0]] 
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * Example 2:
 * 
 * 
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 * 
 * 
 * Note:
 * 
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 */
//#include "header.h"

class Solution {
    bool loop;
    vector<vector<int>> edge;
    vector<bool> visited, inStack;

    void dfs(int u) {
        if (loop)
            return;

        if (inStack[u]) {
            loop = true;
            return;
        }

        if (visited[u])
            return;
        visited[u] = true;

        inStack[u] = true;
        for (int i = 0; i < edge[u].size(); ++i)
            dfs(edge[u][i]);
        inStack[u] = false;
    }

public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        visited.resize(numCourses);
        inStack.resize(numCourses);
        edge.resize(numCourses);
        for (auto p: prerequisites)
            edge[p.second].push_back(p.first);
        loop = false;
        for (int i = 0; i < numCourses; ++i) {
            dfs(i);
            if (loop)
                return false;
        }
        return true;
    }
};

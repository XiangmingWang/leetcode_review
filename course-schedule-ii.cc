//https://leetcode.com/problems/course-schedule-ii/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        vector<int> degree(numCourses, 0);
        for (const auto& pair : prerequisites) {
            graph[pair.second].insert(pair.first);
        }
         for (auto neighbors : graph)
            for (int neigh : neighbors)
                degree[neigh]++;
        queue<int> q;
        for (int i = 0; i < degree.size(); ++i) {
            if (!degree[i]) q.push(i);
        }
        vector<int> result;
        for (int i = 0; i < numCourses; i++) {
            if (q.empty()) return {};
            int now = q.front();
            q.pop();
            result.push_back(now);
            for (int neigh : graph[now]) {
                if (!--degree[neigh])
                    q.push(neigh);
            }
        }
        return result;
    }
};

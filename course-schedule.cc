//https://leetcode.com/problems/course-schedule/
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        vector<int> degrees(numCourses, 0);
        InitGraph(prerequisites, graph, degrees);
        for (int i = 0; i < numCourses; ++i) {
            int j = 0;
            for (; j < numCourses; j++)
                if (!degrees[j]) break;
            if (j == numCourses) return false;
            degrees[j] = -1;
            for (int neigh : graph[j])
                degrees[neigh]--;
        }
        return true; 
    }
private:
    void InitGraph(const vector<pair<int, int>>& prerequisites,
                   vector<unordered_set<int>>& graph,
                   vector<int>& degrees) {
        for (const auto& pair : prerequisites) {
            graph[pair.second].insert(pair.first);
        }
        for (auto neighbors : graph)
            for (int neigh : neighbors)
                degrees[neigh]++;
    }
};

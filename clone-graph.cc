//https://leetcode.com/problems/clone-graph/
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode*> visited;
        return Clone(node, visited);
    }
    UndirectedGraphNode *Clone(UndirectedGraphNode *node,
                               unordered_map<int, UndirectedGraphNode*>& visited) {
        if (!node) return NULL;
        if (visited.find(node->label) != visited.end()) return visited[node->label];
        UndirectedGraphNode* new_node = new UndirectedGraphNode(node->label);
        visited[node->label] = new_node;
        for (const auto& nei : node->neighbors) {
            new_node->neighbors.push_back(Clone(nei, visited));    
        }
        return new_node;
    }
};

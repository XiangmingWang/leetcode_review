/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
  		queue<TreeNode*> q;
		if (root) q.push(root);
		vector<vector<int> > result;
		while(!q.empty()) {
			vector<int> level;
			vector<TreeNode*> level_nodes;
			while(!q.empty()) {
			    TreeNode* node = q.front();
			    q.pop();
			    level.push_back(node->val);
				level_nodes.push_back(node);
			}
			for (int i = 0; i < level_nodes.size(); ++i) {
				TreeNode* node = level_nodes[i];
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			result.push_back(level);
		}      
		return result;
    }
};

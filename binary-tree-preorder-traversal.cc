//https://leetcode.com/problems/binary-tree-preorder-traversal/
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
    vector<int> preorderTraversal(TreeNode* root) {
    	vector<int> result;
		if (!root) return result;
		stack<TreeNode*> s;
		s.push(root);
		TreeNode* node;
		while (!s.empty()) {
			node = s.top();
			s.pop();
			result.push_back(node->val);
			if (node->right) {
				s.push(node->right);
			}
			if (node->left) {
				s.push(node->left);
			}
		}  
		return result;
    }
};

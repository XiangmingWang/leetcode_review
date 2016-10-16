//https://leetcode.com/problems/generate-parentheses/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> result;
		if (n == 0) return result;
		string s;
  		int len = 2 * n;
		dfs(len, 0, 0, &s, &result);      
		return result;
    }
	void dfs(const int& len, const int& now, const int& left,
			 string* s, vector<string>* result) {
		if (s->size() == len) {
			result->push_back(*s);
			return;
		}
		int right = now - left;
		if (left == right || left != len / 2) {
			s->push_back('(');
			dfs(len, now+1, left+1, s, result);
			s->pop_back();
		}
		if (left == len / 2 || left != right){
			s->push_back(')');
			dfs(len, now+1, left, s, result);
			s->pop_back();
		} 
	}
};

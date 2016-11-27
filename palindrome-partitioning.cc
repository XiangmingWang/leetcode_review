//https://leetcode.com/problems/palindrome-partitioning/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> tmp;
        dfs(s, 0, tmp, result);
        return result;
    }
    void dfs(const string& s, int now,
             vector<string>& tmp,
             vector<vector<string>>& result) {
        if (now == s.size()) {
            result.push_back(tmp);
            return;
        }
        for (int i = 1; i + now <= s.size(); ++i) {
            const string& t = s.substr(now, i);
            if (Check(t)) {
                tmp.push_back(t);
                dfs(s, now + i, tmp, result);
                tmp.pop_back();
            }
        }
    }
    bool Check(const string& s) {
        int start = 0, end = s.size() - 1;
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
};

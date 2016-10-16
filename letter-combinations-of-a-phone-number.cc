//https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;
        string m[] = {" ", "", "abc", "def", "ghi",
                      "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string s;
        dfs(digits, m, 0, s, result);
        return result;
    }
    void dfs(const string& digits, const string m[], const int& now,
             string& s, vector<string>& result) {
        if (now == digits.size()) {
            result.push_back(s);
            return;
        }
        string tmp = m[digits[now] - '0'];
        for (const auto& c : tmp) {
            s.push_back(c);
            dfs(digits, m, now+1, s, result);
            s.pop_back();
        }
    }
};

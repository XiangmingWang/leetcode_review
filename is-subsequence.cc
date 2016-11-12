//https://leetcode.com/problems/is-subsequence/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        vector<bool> dp;
        int n = s.size();
        int idx = 0;
        char now = s[idx];
        for (const auto& c : t) {
            if (s[idx] == c) {
                ++idx;
                if (idx == n) return true;
            }
        }    
        return false;
    }
};

//https://leetcode.com/problems/first-unique-character-in-a-string/
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> flag(256, 0);
        for (const char c : s) ++flag[c];
        for (int i = 0; i < s.size(); ++i) {
            if (flag[s[i]] == 1) return i;
        }
        return -1;
    }
};

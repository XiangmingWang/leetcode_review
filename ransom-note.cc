//https://leetcode.com/problems/ransom-note/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> m(26, 0);
        for (const auto& c : magazine) {
            ++m[c-'a'];
        }
        for (const auto& c: ransomNote) {
            if (--m[c-'a'] < 0) return false;
        }
        return true;
    }
};

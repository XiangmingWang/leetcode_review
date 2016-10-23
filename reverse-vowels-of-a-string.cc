//https://leetcode.com/problems/reverse-vowels-of-a-string/
class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        vector<bool> flag(128, false);
        flag['a'] = true;
        flag['e'] = true;
        flag['i'] = true;
        flag['o'] = true;
        flag['u'] = true;
        flag['A'] = true;
        flag['E'] = true;
        flag['I'] = true;
        flag['O'] = true;
        flag['U'] = true;
        while (left < right) {
            if (!flag[s[left]]) ++left;
            else if (!flag[s[right]]) --right;
            else swap(s[left++], s[right--]);
        }
        return s;
    }
};

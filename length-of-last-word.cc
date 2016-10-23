//https://leetcode.com/problems/length-of-last-word/
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int end = s.size() - 1;
        while(s[end] == ' ' && end >= 0) --end;
        int i = end;
        for (; i >= 0; --i) {
            if (s[i] == ' ') return end - i;
        }
        return end - i;
    }
};

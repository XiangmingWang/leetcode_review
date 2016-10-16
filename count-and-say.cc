//https://leetcode.com/problems/count-and-say/
class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) return "";
        string start = "1";
        for (int i = 1; i < n; ++i) {
            start = count(start);
        }
        return start;
    }
    string count(string s) {
        stringstream ss;
        char last = s[0];
        int count = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != last) {
                ss << count << last;
                last = s[i];
                count = 1;
            } else {
                ++count;
            }
        }
        ss<<count<<last;
        return ss.str();
    }
};

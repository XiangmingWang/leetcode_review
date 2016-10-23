//https://leetcode.com/problems/minimum-window-substring/
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128,0);
        for (const auto& c : t) ++need[c];
        int count = t.size(), start = 0, end = 0, width = INT_MAX, min_start = 0;
        while (end < s.size()) {
            if (need[s[end++]]-- > 0) --count;
            while (count == 0) {
                if (end - start < width) {
                    width = end - start;
                    min_start = start;
                }
                if (++need[s[start++]] > 0) ++count;
            }
        }
        return width == INT_MAX ? "" : s.substr(min_start, width);
    }
};

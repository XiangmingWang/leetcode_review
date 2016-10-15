//https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int locs[256];
        fill(locs, locs + 256, -1);
        int start = 0, max_len = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (locs[s[i]] >= start) {
                max_len = max(i - start, max_len);
                start = locs[s[i]] + 1;
            }
            locs[s[i]] = i;
        }
        return max((int)s.size() - start, max_len);
    }
};

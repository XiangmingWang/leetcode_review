//https://leetcode.com/problems/assign-cookies/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ret = 0;
        for (int i = 0, j = 0; i < g.size() && j < s.size(); ++j) {
            if (s[j] < g[i]) {
                continue;
            }
            ++ret;
            ++i;
        }
        return ret;
    }
};

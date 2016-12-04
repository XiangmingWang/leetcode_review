//https://leetcode.com/problems/h-index-ii/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        int ret = 0;
        for (int i = citations.size() - 1; i >= 0; --i) {
            if (citations[i] < ret + 1) return ret;
            ++ret;
        }
        return ret;
    }
};

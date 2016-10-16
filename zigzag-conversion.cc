//https://leetcode.com/problems/zigzag-conversion/
class Solution {
public:
    string convert(string s, int numRows) {
        int loop = 2 * numRows - 2;
        if (loop == 0) return s;
        string ret;
        vector<int> line(loop, 0);
        vector<string> result(numRows);
        for (int i = 0; i < numRows; ++i) {
            line[i] = i;
        }
        for (int i = numRows; i < loop; ++i) {
            line[i] = loop - i;
        }
        for (int i = 0; i < s.size(); ++i) {
            result[line[i % loop]] += s[i];
        }
        for (int i = 0; i < numRows; ++i) {
            ret += result[i];
        }
        return ret;
    }
};

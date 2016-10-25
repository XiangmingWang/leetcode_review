//https://leetcode.com/problems/reverse-string/
class Solution {
public:
    string reverseString(string s) {
      if (s.empty()) return s;
        string result = s;
      for (int i = 0, j = s.size() - 1; i < s.size(); ++i, --j) {
         result[i] = s[j];
      }
      return result;
    }
};

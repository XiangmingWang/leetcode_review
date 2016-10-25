//https://leetcode.com/problems/longest-common-prefix/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      if (strs.empty()) return "";
         int i = 0;
      char tmp;
      while (true) {
         if (i == strs[0].size()) return strs[0].substr(0, i);
         tmp = strs[0][i];
         for (int j = 1; j < strs.size(); ++j) {
            if (i >= strs[j].size() || strs[j][i] != tmp) return strs[0].substr(0, i);
         }
         ++i;
      }     
      return strs[0];
    }
};

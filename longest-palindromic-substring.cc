#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
   string expandFromCenter(const string& s, const int& left, const int& right) {
      int i = left, j = right;
      bool flag = false;
      if (s[left] == s[right]) {
         flag = true;
      } 
      if (!flag) return "";
      while ((i - 1 >= 0) &&
            (j + 1 < s.size()) &&
            (s[i-1] == s[j+1])) {
         --i, ++j;
         flag = true;
      }
      if (flag)
         return s.substr(i, j - i + 1);
      return s.substr(left, 1);

   }
   string longestPalindrome(string s) {
      string result;
      if (s.empty()) return result;
      int max_len = 0;
      for (int i = 0; i < s.size(); ++i) {
         string s1 = expandFromCenter(s, i, i);
         string s2 = expandFromCenter(s, i, i+1);
         cout << s1 << " , " << s2 << endl;
         if (s1.size() > max_len) {
            max_len = s1.size();
            result = s1;
         }
         if (s2.size() > max_len) {
            max_len = s2.size();
            result = s2;
         }

      }
      return result;
   }
};
int main() {
   string s = "aaabaaaa";
   Solution sl;
   cout << sl.longestPalindrome(s) << endl;
}

//https://leetcode.com/problems/multiply-strings/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
      if (num1 == "0" || num2 == "0") return "0";
        vector<int> result;
      int tmp = 0, c = 0;
      int len1 = num1.size(), len2 = num2.size();
      for (int i = 0; i < num1.size(); ++i) {
         for (int j = 0; j <= num2.size(); ++j) {
            if (j != num2.size()) tmp = (num1[len1-1-i] - '0') * (num2[len2-1-j] - '0') + c;
            else tmp = c;
            if (result.size() < (i + j + 1)) {
               result.push_back(tmp % 10);
               c = tmp / 10;
            } else {
               tmp += result[i+j];
               result[i+j] = tmp % 10;
               c = tmp / 10;
            }
         }
      }
      if (c > 0) result.push_back(c);
      string ret;
      int i = result.size() - 1;
      while (i >= 0 && result[i] == 0) --i;
      for (; i >= 0; --i) {
         ret.push_back(result[i] + '0');
      }
      return ret;
    }
};
int main() {
   Solution s;
   string s1 = "1";
   string s2 = "0";
   cout << s.multiply(s1, s2) << endl;
   cout << atoi(s1.c_str()) * atoi(s2.c_str()) << endl;
}


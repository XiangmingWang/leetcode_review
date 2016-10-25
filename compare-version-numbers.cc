//https://leetcode.com/problems/compare-version-numbers/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
      vector<int> v1, v2;
      string tmp;
        stringstream ss1(version1);
        stringstream ss2(version2);
      GetVec(ss1, &v1);
      GetVec(ss2, &v2);
      int i = 0;
      while ((i < v1.size()) && (i < v2.size())) {
         cout << "v1: " << v1[i] << ", v2: " << v2[i] <<endl; 
         if (v1[i] == v2[i]) ++i;
         else return v1[i] > v2[i] ? 1 : -1;
      }
      while (i < v1.size()) {
         if (v1[i++] != 0) return 1;
      }
      while (i < v2.size()) {
         if (v2[i++] != 0) return -1;
      }
      return 0;
    }
private:
   void GetVec(stringstream& ss, vector<int>* v) {
      string tmp;
      while (getline(ss, tmp, '.')) {
         cout << tmp <<endl;
         v->push_back(atoi(tmp.c_str()));
      }
   }
};
int main() {
   string s1 = "1.0", s2 = "1";
   Solution s;
   cout << s.compareVersion(s1, s2) << endl;

}

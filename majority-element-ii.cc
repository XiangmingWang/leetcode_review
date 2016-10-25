//https://leetcode.com/problems/majority-element-ii/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      vector<int> result;
      int n1 = 0, n2 = 0, c1 = 0, c2 = 0;
       for (const auto& n : nums) {
         if (n == n1) {
            ++c1;
         } else if (n == n2) {
            ++c2;
         } else if (c1 == 0) {
            n1 = n;
            ++c1;
         } else if (c2 == 0) {
            n2 = n;
            ++c2;
         } else {
            --c1;
            --c2;
         }
      }
      c1 = 0, c2 = 0;
      for (const auto& n : nums) {
         if (n == n1) ++c1;
         else if (n == n2) ++c2;
      }
      if (c1 > nums.size()/3.0) result.push_back(n1);
      if (c2 > nums.size()/3.0) result.push_back(n2);
      return result;
    }
};

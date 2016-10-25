//https://leetcode.com/problems/rotate-function/
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
      if (A.empty()) return 0;
      int result = INT_MIN, sum = 0, tmp = 0;
      for (int i = 0; i < A.size(); ++i) {
         sum += A[i];
         tmp += A[i] * i;
      }
      result = max(result, tmp);
      for (int i = 0; i < A.size(); ++i){
         tmp = tmp - sum + A.size() * A[i];
         result = max(result, tmp);
      }
      return result;
    }
};

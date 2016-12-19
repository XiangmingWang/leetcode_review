#include "leetcode.h"

class Solution {
public:
    int hammingDistance(int x, int y) {
      int dist = 0, val = x ^ y;
      while (val) {
          ++dist;
          val &= val - 1;
      }
      return dist;
    }
};

int main() {
    Solution s;
    cout << s.hammingDistance(1, 4);
}

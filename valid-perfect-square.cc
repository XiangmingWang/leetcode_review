//https://leetcode.com/problems/valid-perfect-square/
#include "leetcode.h"
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long left = 1, right = num, mid;
        while (left <= right) {
            mid = (right + left) / 2;
            if (mid >= 50000) mid = 50000;
            long long tmp = mid * mid;
            if (tmp == num) return true;
            else if (tmp < num) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
    
};

int main() {
    Solution s;
    int i = 2147483647;
    cout << s.isPerfectSquare(i) << endl;
}

//https://leetcode.com/problems/sqrtx/
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        int left = 1, right = x, mid, n, m;
        int result = left;
        while (left <= right) {
            mid = left + (right - left) / 2;
            n = x / mid;
            m = x % mid;
            if ((n == mid) && (m == 0)) {
                return mid;
            } else if (n < mid) {
                right = mid - 1;
            } else {
                result = mid;
                left = mid + 1;
            }
        }
        return result;
    }
};

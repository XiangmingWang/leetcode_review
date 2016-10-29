//https://leetcode.com/problems/powx-n/
class Solution {
public:
    double myPow(double x, int n) {
        if (n == INT_MIN) return 1/(myPow(x, INT_MAX) * x);
        if (n < 0) return 1/myPow(x, -n);
        if (n == 0) return 1;
        if (x == 0) return 0;
        if (n == 1) return x;
        double tmp; 
        if (n % 2 == 0) {
            tmp = myPow(x, n/2);
            return tmp * tmp;
        }
        tmp = myPow(x, (n-1)/2);
        return tmp * tmp * x;
    }
};

//https://leetcode.com/problems/divide-two-integers/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1))  return INT_MAX;
        bool neg = (dividend < 0) ^ (divisor < 0);
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int result = 0;
        while (dvd >= dvs) {
            long long sub = dvs, times = 1;
            while (dvd >= (sub << 1)) {
                sub <<= 1;
                times <<= 1;
            }
            dvd -= sub;
            result += times;
        }
        return neg ? -result : result;
    }
};

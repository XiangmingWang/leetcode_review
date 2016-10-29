//https://leetcode.com/problems/reverse-integer/
class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        int y = 0;
        if (x < 0) {
            neg = true;
            x = -x;
        }
        while (x > 0) {
            if (y > (INT_MAX - x % 10) / 10) return 0;
            y = y * 10 + x % 10;
            x /= 10;
        }
        return neg ? -y : y;
    }
};

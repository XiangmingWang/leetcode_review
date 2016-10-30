//https://leetcode.com/problems/happy-number/
class Solution {
public:
    bool isHappy(int n) {
        if (n < 10) {
            if ((n == 7) || (n == 1)) return true;
            else return false;
        }
        int next = 0;
        while (n > 0) {
            next += (n % 10) * (n % 10)
            n /= 10;
        }
        return isHappy(next);
    }
};

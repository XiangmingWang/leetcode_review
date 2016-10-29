//https://leetcode.com/problems/palindrome-number/
class Solution {
public:
    bool isPalindrome(int x) {
        int m = 1;
        if (x < 0 ) return false;
        while (true) {
            if (m > x / 10) break;
            m *= 10;
        }
        return Check(x, m);
    }
    bool Check(int x, int m) {
        if (m <= 1) return true;
        if (x % 10 == x / m) {
            x = (x % m) / 10;
            return Check(x, m / 100);
        }
        return false;
    }
};

//https://leetcode.com/problems/integer-break/
class Solution {
public:
    int integerBreak(int n) {
        return n < 4 ? n - 1 : n%3 == 0 ? pow(3,n/3) : pow(3,n/3-1) * (2+2*(n%3));      
    }
};

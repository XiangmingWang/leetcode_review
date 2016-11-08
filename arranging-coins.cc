//https://leetcode.com/problems/arranging-coins/
class Solution {
public:
    int arrangeCoins(int n) {
        int ans=0;  
        if(n==0) return 0;  
        if(n==1) return 1;  
        ans=(int)((sqrt(1+8*(long)n)-1)/2);  
        return ans;  
    }
};

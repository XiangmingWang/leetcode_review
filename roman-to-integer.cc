//https://leetcode.com/problems/roman-to-integer/
class Solution {
public:
    int romanToInt(string s) {
        int m[26] = {0,0,100,500,0,0,0,0,1,0,0,50,1000,0,0,0,0,0,0,0,0,5,0,10,0,0};
        int result = 0, vmax = 0;
        for (int i = s.size() - 1; i >= 0; --i){
            int t = m[s[i]-'A'];
            if (t >= vmax){
                result += t;
                vmax = t;
            }else{
                result -= t;
            }
        }
        return result;
    }
};

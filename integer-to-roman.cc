//https://leetcode.com/problems/integer-to-roman/
class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        int base[] = {1000,500,100,50,10,5,1,0};
        char baseC[] = {'M','D','C','L','X','V','I'};
        int basen = 0;
        while(num) {
            if(basen%2 == 0 && num/base[basen] == 4) {
                result += baseC[basen];
                result += baseC[basen-1];
                num -= base[basen] * 4;
            } else if(num >= base[basen]) {
                result += baseC[basen];
                num -= base[basen];
            } else if(basen%2 == 0 && num / base[basen+2] == 9) {
                result += baseC[basen+2];
                result += baseC[basen];
                num -= base[basen+2]*9;
            } else {
                basen++;
            }
        }
        return result;
    }
};

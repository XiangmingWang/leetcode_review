//https://leetcode.com/problems/string-to-integer-atoi/
class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        int idx = 0, tmp = 0;
        long long result = 0;
        bool pos = true;
        for (;idx < str.size(); ++idx) {
            if (str[idx] != ' ') break;
        }
        if (str[idx] == '+') {
            ++idx;
        } else if (str[idx] == '-') {
            pos = false;
            ++idx;
        }
        for (;idx < str.size(); ++idx) {
            if (str[idx] >= '0' && str[idx] <= '9') {
                tmp = result;
                result = result * 10 + (str[idx] - '0');
                if (result > INT_MAX) return pos ? INT_MAX : INT_MIN;
            } else {
                break;
            }
        }
        if (!pos) return -result;
        return result;
    }
};

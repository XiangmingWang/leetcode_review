//https://leetcode.com/problems/add-strings/
class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.empty()) return num2;
        if (num2.empty()) return num1;
        int idx1 = num1.size() - 1;
        int idx2 = num2.size() - 1;
        stringstream ss;
        int c = 0;
        while (idx1 >= 0 && idx2 >= 0) {
            int sum =  num1[idx] - '0' + num2[idx] - '0' + c;
            ss << sum % 10;
            c = sum / 10;
            --idx1, --idx2;
        }
        while (idx1 >= 0) {
            int sum = num1[idx1] - '0' + c;
            ss << sum % 10;
            c = sum / 10;
            --idx1;
        }
        while (idx2 >= 0) {
            int sum = num2[idx2] - '0' + c;
            ss << sum % 10;
            c = sum / 10;
            --idx2;
        }
        if (c > 0) ss << c;
        string result = ss.str();
        reverse(result.begin(), result.end());
        return result;
    }
};

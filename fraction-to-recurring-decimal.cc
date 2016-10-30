//https://leetcode.com/problems/fraction-to-recurring-decimal/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        if (denominator == 0) return "";
        stringstream ss;
        long long num = numerator, den = denominator;
        long long tmp_i = num / den;
        int tmp_j = num % den;
        if (tmp_j == 0) {
            ss << tmp_i;
            return ss.str();
        } else {
            if (tmp_i == 0) {
                bool neg = (num < 0) ^ (den < 0);
                if (neg) ss << "-0.";
                else ss << "0.";
            } else {
                ss << tmp_i << '.';
            }
        }
        map<int, size_t> m;
        size_t offset = ss.str().size();
        num = abs(tmp_j);
        den = abs(den);
        cout << tmp_j << endl;
        m[num] = offset;
        while (num > 0) {
            num *= 10;
            int i = num / den;
            int j = num % den;
            ss << i;
            if (m.find(j) != m.end()) {
                string now = ss.str();
                return now.substr(0, m[j]) + "(" + now.substr(m[j]) + ")";
            }
            m[j] = ++offset;
            num = j;
        }
        return ss.str();
    }
};
int main() {
    Solution s;
    cout << s.fractionToDecimal(INT_MIN,-1999)<<endl;
}

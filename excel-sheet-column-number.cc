//https://leetcode.com/problems/excel-sheet-column-number/
#include "leetcode.h"
class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;      
        for (const auto&c : s) {
            result = result * 26 + c - 'A' + 1;
        }
        return result;
    }
};
int main() {
    Solution s;
    cout << s.titleToNumber("AA") << endl;
    cout << s.titleToNumber("A") << endl;
    cout << s.titleToNumber("IZ") << endl;
}

//https://leetcode.com/problems/excel-sheet-column-title/
#include "leetcode.h"
class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n > 0) {
            result.push_back((n-1)%26 + 'A');
            n = (n-1)/26;
        }      
        reverse(result.begin(), result.end());
        return result;
    }
};
int main() {
    Solution s;
    cout<<s.convertToTitle(26)<<endl;
    cout<<s.convertToTitle(1)<<endl;
    cout<<s.convertToTitle(260)<<endl;
}

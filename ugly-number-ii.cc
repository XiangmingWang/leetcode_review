//https://leetcode.com/problems/ugly-number-ii/
#include "leetcode.h"
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v(n, 1);
        int n2 = 2, n3 = 3, n5 = 5;
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < n; ++i) {
            int last = v[i] =  min(n2, min(n3, n5));
            while (n2 <= last) n2 = 2 * v[++i2];
            while (n3 <= last) n3 = 3 * v[++i3];
            while (n5 <= last) n5 = 5 * v[++i5];
        }
        return v[n-1];

    }
};
int main() {
    Solution s;
    cout << s.nthUglyNumber(67) << endl;
}

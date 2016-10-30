//https://leetcode.com/problems/count-primes/
#include "leetcode.h"
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> is_prime(n, true);
        int up_bound = sqrt(n);
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (is_prime[i-1]) {
                ++count;
                if (i > up_bound) continue;
                for (int j = i; j * i < n; ++j) {
                    is_prime[j*i-1] = false;
                }
            }
        }
        return count;
    }
};
int main() {
    Solution s;
    cout << s.countPrimes(5) << endl;
}

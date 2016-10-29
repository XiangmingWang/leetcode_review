//https://leetcode.com/problems/permutation-sequence/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n, 0);
        string result;
        GetP(n,k-1,nums,result);
        return result;
    }
    void GetP(int n, int k, vector<int>& nums, string& result) {
        if (n == 1) {
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == 0) {
                    result.push_back(i + 1 + '0');
                    break;
                }
            }
            return;
        }
        int loop_count = Fun(n-1);
        int turn = k / loop_count + 1;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) continue;
            ++j;
            if (j == turn) {
                nums[i] = 1;
                result.push_back(i + 1 + '0');
                break;
            }
        }
        GetP(n-1, k % loop_count, nums, result);
    }
    int Fun(int x) {
        int res = 1;
        while (x > 0) {
            res *= x;
            --x;
        }
        return res;
    }
};
int main() {
    Solution s;
    cout<<s.getPermutation(1,1) <<endl;
    cout<<s.getPermutation(2,1) <<endl;
    cout<<s.getPermutation(3,1) <<endl;
    cout<<s.getPermutation(3,5) <<endl;
}

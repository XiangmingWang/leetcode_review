//https://leetcode.com/problems/restore-ip-addresses/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> now;
        FindIP(s, 0, &now, &result);    
        return result;
    }
    void FindIP(const string& s, int idx, vector<string>* now_ptr, vector<string>* result) {
        vector<string> &now = *now_ptr;
        if (now.size() == 4) {
            if (idx == s.size())
                result->push_back(now[0]+"."+now[1]+"."+now[2]+"."+now[3]);
            return;
        }
        if (idx >= s.size()) return;
        if (s[idx] == '0') {
            now.push_back("0");
            FindIP(s, idx+1, &now, result);
            now.pop_back();
            return;
        }
        for (int i = 1; i <= 3; ++i) {
            string tmp = s.substr(idx,i);
            if (i == 3 && stoi(tmp) > 255) continue;
            now.push_back(tmp);
            FindIP(s, idx+i, &now, result);
            now.pop_back();
        }
    }
};

int main() {
    Solution s;
    //string str = "25525511135";
    string str = "010010";
    for (auto& ss : s.restoreIpAddresses(str)) {
        cout << ss << endl;
    }
}

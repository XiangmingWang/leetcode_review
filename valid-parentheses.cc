//https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        string left = "([{";
        string right = ")]}";
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            if (left.find(s[i]) != string::npos) {
                st.push(s[i]);
            } else {
                int r_idx = right.find(s[i]);
                if (r_idx == string::npos) continue;
                if(st.empty() || left[r_idx] != st.top()) return false;
                st.pop();
            }
        }
        if (st.empty()) return true;
        return false;
    }
};

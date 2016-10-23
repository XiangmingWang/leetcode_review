//https://leetcode.com/problems/simplify-path/
class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        vector<string> tups;
        string tmp, result;
        while (getline(ss, tmp, '/')) {
            if (tmp.empty() || tmp == ".") continue;
            if (tmp == "..") {
                if (!tups.empty()) tups.pop_back();
            } else {
                tups.push_back(tmp);
            }
        }
        for (const auto& s : tups) {
            result += "/" + s;
        }
        return result.empty() ? "/" : result;
    }
};

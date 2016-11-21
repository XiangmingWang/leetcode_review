//https://leetcode.com/problems/repeated-dna-sequences/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        unordered_map<string, int> m;
        if (s.size() <= 10) return result;
        for (int i = 0; i <= s.size() - 10; ++i) {
            const string& key = s.substr(i, 10);
            if (m.find(key) == m.end()) {
                m[key] = 0;
            }
            ++m[key];
        }
        for (const auto& pair : m) {
            if (pair.second <= 1) continue;
            result.push_back(pair.first);
        }
        return result;
    }
};

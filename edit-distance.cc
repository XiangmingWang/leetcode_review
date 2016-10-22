//https://leetcode.com/problems/edit-distance/
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty()) return word2.size();
        if (word2.empty()) return word1.size();
        size_t len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (size_t i = 0; i <= len1; ++i) {
            dp[i][0] = i;
        }
        for (size_t j = 0; j <= len2; ++j) {
            dp[0][j] = j;
        }
        for (size_t i = 1; i <= len1; ++i) {
            for (size_t j = 1; j <= len2; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j-1] + 1, min(dp[i-1][j] + 1, dp[i][j-1] + 1));
                }
            }
        }
        return dp[len1][len2];
    }
};

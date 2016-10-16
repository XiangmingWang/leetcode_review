//https://leetcode.com/problems/implement-strstr/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
		if (haystack.size() < needle.size()) return -1;
		for (int i = 0; i <= haystack.size() - needle.size(); ++i) {
			int j = i, k = 0;
			while(j < haystack.size() && haystack[j] == needle[k]) {
				++j; ++k;
				if (k == needle.size()) return i;
			}
		}
		return -1;
    }
};

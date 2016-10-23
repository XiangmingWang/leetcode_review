//https://leetcode.com/problems/add-binary/
class Solution {
public:
    string addBinary(string a, string b) {
		if (a.empty()) return b;
		if (b.empty()) return a;
    	int la = a.size() - 1, lb = b.size() - 1;
		string result;
		int c = 0;
		int tmp;
		while(la >= 0 && lb >= 0) {
			tmp = a[la] - '0' + b[lb] - '0' + c;
			c = tmp / 2;
			result.push_back(tmp % 2 + '0');
			--la , --lb;
		}
		while(la >= 0) {
			tmp = a[la] - '0' + c;
			c = tmp / 2;
			result.push_back(tmp % 2 + '0');
			--la;
		}
		while(lb >= 0) {
			tmp = b[lb] - '0' + c;
			c = tmp / 2;
			result.push_back(tmp % 2 + '0');
			--lb;
		}
		if (c == 1) result.push_back('1');
		reverse(result.begin(), result.end());
		return result;
    }
};

//https://leetcode.com/problems/find-the-duplicate-number/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
		int left = 1, right = nums.size();
		while (left <= right) {
			int count = 0;
			mid = (left + right) / 2;
			for (const auto& i : nums) {
				if (i <= mid) ++count;
			}
			if (count > mid) right = mid - 1;
			else left = mid + 1;
		}
		return left;
    }
};

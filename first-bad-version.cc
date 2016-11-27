//https://leetcode.com/problems/first-bad-version/
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int begin = 0, end = n - 1, mid, result = 1;
        while (begin <= end) {
            mid = begin + (end - begin) / 2;
            if (isBadVersion(mid+1)) {
                result = mid + 1;
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        return result;
    }
};

#include "leetcode.h"
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        set<int> heater_set;
        for (auto heater : heaters) {
            heater_set.insert(heater);
        }
        
        int result = 0, dis;
        
        for (const int house : houses) {
            auto iter = heater_set.lower_bound(house);
            if (iter == heater_set.begin()) {
                dis = abs(*iter - house);
            } else if (iter == heater_set.end()) {
                auto l_iter = next(iter, -1);
                dis = abs(*l_iter - house);
            } else {
                auto l_iter = next(iter, -1);
                dis = min(abs(*iter - house), abs(*l_iter - house));
            }
            result = max(dis, result);
        }
        return result;
    }
    
};
int main() {
    Solution s;
    vector<int> houses, heaters;
    houses.push_back(1);
    houses.push_back(2);
    houses.push_back(3);
    houses.push_back(4);
    heaters.push_back(1);
    heaters.push_back(4);
    cout <<s.findRadius(houses, heaters);
}

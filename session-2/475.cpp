// 475. Heaters
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());

        int result = 0;
        for (int house: houses) {
            auto lower = lower_bound(heaters.begin(), heaters.end(), house);
            if (lower == heaters.end()) {
                result = max(result, house - heaters[heaters.size() - 1]);
            } else {
                if (lower > heaters.begin()) {
                    result = max(result, min(house - *(lower - 1), *lower - house));
                } else {
                    result = max(result, *lower - house);
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> a{1, 2, 3}, a1{1};
    vector<int> b{1, 2, 3, 4}, b1{1, 4};
    Solution s;

    cout << s.findRadius(a, a1) << endl;
    cout << s.findRadius(b, b1) << endl;
}
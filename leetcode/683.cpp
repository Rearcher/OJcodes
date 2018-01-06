// 683. K Empty Slots
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        vector<int> days(flowers.size());
        for (int i = 0; i < flowers.size(); ++i) days[flowers[i] - 1] = i + 1;

        int left = 0, right = k + 1, result = INT_MAX;
        for (int i = 0; right < days.size(); ++i) {
            if (days[i] < days[left] || days[i] <= days[right]) {
                if (i == right) result = min(result, max(days[left], days[right]));
                left = i;
                right = i + k + 1;
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};

int main() {
    vector<int> flowers{1, 3, 2};
    Solution s;
    cout << s.kEmptySlots(flowers, 1) << endl;
}
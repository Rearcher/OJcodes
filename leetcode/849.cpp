// 849. Maximize Distance to Closest Person
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int d = -1;
        int lastOne = -1;
        for (int i = 0; i < seats.size(); ++i) {
            if (seats[i] == 0) continue;

            int cur;
            if (lastOne == -1) {
                cur = i;
            } else {
                cur = i - lastOne - 1;
                cur = (cur % 2 == 0) ? (cur / 2) : (cur / 2 + 1);
            }
            d = max(d, cur);
            lastOne = i;
        }
        
        int cur = seats.size() - lastOne - 1;
        d = max(d, cur);
        return d;
    }
};

int main() {
    Solution s;
    // vector<int> seats{1, 0, 0, 0, 1, 0, 1};
    vector<int> seats{1, 0, 0, 1};
    cout << s.maxDistToClosest(seats) << "\n";
}
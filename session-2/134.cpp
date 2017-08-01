// 134. Gas Station
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i = 0;

        while (i < gas.size()) {
            int tank = 0, j = 0;

            for (; j < gas.size(); ++j) {
                int k = (i + j) % gas.size();
                tank += gas[k] - cost[k];
                if (tank < 0) break;
            }

            if (j >= gas.size()) return i;
            i += j + 1;
        }

        return -1;
    }
};

int main() {
    Solution s;
    // vector<int> gas{6, 1, 4, 3, 5}, cost{3, 8, 2, 4, 2};
    vector<int> gas{4}, cost{5};
    cout << s.canCompleteCircuit(gas, cost) << endl;
}
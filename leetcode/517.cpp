// 517. Super Washing Machines
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0);
        if (sum % machines.size()) return -1;
        
        int result = 0, cnt = 0, avg = sum / machines.size();
        for (int i = 0; i < machines.size(); ++i) {
            int val = machines[i] - avg;
            cnt += val;
            result = max(result, max(val, abs(cnt)));
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> a{9, 1, 8, 8, 9};
    cout << s.findMinMoves(a) << endl;
}
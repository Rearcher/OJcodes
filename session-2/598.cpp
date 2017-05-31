// 598. Range Addition II
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int op1 = m, op2 = n;
        for (vector<int> op : ops) {
            op1 = min(op1, op[0]);
            op2 = min(op2, op[1]);
        }
        return op1 * op2;
    }
};

int main() {
    Solution s;
    vector<vector<int>> ops;
    ops.push_back(vector<int>{2, 2});
    ops.push_back(vector<int>{3, 3});
    cout << s.maxCount(3, 3, ops) << endl;
}
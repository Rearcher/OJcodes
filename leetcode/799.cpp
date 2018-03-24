// 799. Champagne Tower
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> t(101, vector<double>(101, 0));
        t[0][0] = poured;

        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (t[i][j] >= 1) {
                    t[i + 1][j] += (t[i][j] - 1) / 2;
                    t[i + 1][j + 1] += (t[i][j] - 1) / 2;
                    t[i][j] = 1;
                }
            }
        }

        return t[query_row][query_glass];
    }
};

int main() {
    Solution s;
    // cout << s.champagneTower(1, 1, 1) << "\n";
    // cout << s.champagneTower(2, 1, 1) << "\n";
    cout << s.champagneTower(1000000000, 99, 99) << "\n";
}
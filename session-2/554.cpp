// 554. Brick Wall
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> m;
        int height = wall.size();

        int mmax = 0;
        for (vector<int> row : wall) {
            if (row.size() == 1) continue;
            int stop = row[0];
            for (int i = 1; i < row.size(); ++i) {
                if (m.count(stop)) {
                    m[stop] += 1;
                } else {
                    m[stop] = 1;
                }

                if (m[stop] > mmax) {
                    mmax = m[stop];
                }

                stop += row[i];
            }
        }

        return height - mmax;
    }
};

int main() {

}
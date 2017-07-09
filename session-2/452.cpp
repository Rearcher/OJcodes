// 452. Minimum Number of Arrows to Burst Balloons
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.empty()) return 0;
        
        sort(points.begin(), points.end(), [&](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.second < p2.second;
        });
        
        int pos = points[0].second;
        int cnt = 1;
        for (int i = 1; i < points.size(); ++i) {
            if (points[i].first <= pos) {
                continue;
            }

            cnt++;
            pos = points[i].second;
        }

        return cnt;
    }
};

int main() {

}
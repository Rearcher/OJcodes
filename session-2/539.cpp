// 539. Minimum Time Difference
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<pair<int, int>> points(timePoints.size());
        for (int i = 0; i < timePoints.size(); ++i) {
            int hour = stoi(timePoints[i].substr(0, 2));
            int minute = stoi(timePoints[i].substr(3));
            points[i] = pair<int, int>{hour, minute};
        }

        sort(points.begin(), points.end(), [&](const pair<int, int>& p1, const pair<int, int>& p2) {
            if (p1.first == p2.first)
                return p1.second < p2.second;
            return p1.first < p2.first;
        });

        for (auto p : points) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << "\n";

        int result = INT_MAX;
        for (int i = 0; i < points.size(); ++i) {
            if (i == 0) {
                result = min(result, calDifference(points[i], points[points.size()-1]));
            } else {
                result = min(result, calDifference(points[i-1], points[i]));
            }
        }

        return result;
    }

private:
    int calDifference(pair<int, int>& p1, pair<int, int>& p2) {
        int diff1 = 0, diff2 = 0;
        diff1 = p2.first * 60 + p2.second - (p1.first * 60 + p1.second);
        diff2 = 24 * 60 - (p2.first * 60 + p2.second) + (p1.first * 60 + p1.second);
        return min(diff1, diff2);
    }
};

int main() {
    Solution s;
    vector<string> timePoints{"00:00", "23:59", "00:00"};

    cout << s.findMinDifference(timePoints) << endl;
}
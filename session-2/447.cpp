// 447. Number of Boomerangs
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int result = 0;
        unordered_map<int, int> m;

        for (int i = 0; i < points.size(); ++i) {
            for (int j = 0; j < points.size(); ++j) {
                if (i == j) {
                    continue;
                }

                int distance = getDistance(points[i], points[j]);
                if (m.find(distance) != m.end()) {
                    m[distance] += 1;
                } else {
                    m[distance] = 1;
                }
            }

            for (unordered_map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
                result += iter->second * (iter->second - 1);
            }

            m.clear();
        }

        return result;
    }

private:
    int getDistance(pair<int, int> a, pair<int, int> b) {
        return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
    }
};

int main() {
    Solution s;
    vector<pair<int, int>> points{pair<int, int>{0, 0}, pair<int, int>{1, 0}, pair<int, int>{2, 0}};
    cout << s.numberOfBoomerangs(points) << endl;
}
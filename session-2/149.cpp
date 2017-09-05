// 149. Max Points on a Line
#include "leetcode.hpp"
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() <= 2) return points.size();

        unordered_map<int, unordered_map<int, int>> m;
        int result = 0;
        for (int i = 0; i < points.size() - 1; ++i) {
            m.clear();
            int overlap = 0, mmax = 0;
            for (int j = i + 1; j < points.size(); ++j) {
                int x = points[i].x - points[j].x, y = points[i].y - points[j].y;
                if (x == 0 && y == 0) {
                    overlap += 1; 
                    continue;
                }

                int g = gcd(x, y);
                if (g != 0) x /= g, y /= g;
                if (m.count(x)) {
                    m[x][y] += 1;
                } else {
                    m[x] = {{y, 1}};
                }

                mmax = max(mmax, m[x][y]);
            }
            result = max(result, mmax + overlap + 1);
        }

        return result;
    }

private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};

int main() {

}
// 587. Erect the Fence
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
    vector<Point> outerTrees(vector<Point>& points) {
        if (points.size() <= 3) return points;

        Point p = points[0];
        for (int i = 1; i < points.size(); ++i)
            if (points[i].y < p.y || (points[i].y == p.y && points[i].x < p.x))
                p = points[i];

        // important! sort by polar order
        sort(points.begin(), points.end(), [&p, this](Point a, Point b) {
            int ccw = counterClockWise(p, a, b);
            if (ccw == 0) return dist(p, a) < dist(p, b);
            return ccw > 0;
        });

        Point a = points[0], b = points[points.size() - 1];
        int i = points.size() - 2;
        while (i >= 0 && counterClockWise(a, b, points[i]) == 0) i--;
        for (int l = i + 1, r = points.size() - 1; l < r; l++, r--) {
            swap(points[l], points[r]);
        }

        stack<Point> st;
        st.push(points[0]);
        st.push(points[1]);
        for (int i = 2; i < points.size(); ++i) {
            Point tmp = st.top();
            st.pop();
            while (st.size() && counterClockWise(st.top(), tmp, points[i]) < 0) {
                tmp = st.top();
                st.pop();
            }
            st.push(tmp), st.push(points[i]);
        }

        vector<Point> result;
        while (st.size()) {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }

private:
    // computer cross product of vector a and vector b
    int crossProduct(Point a, Point b) {
        int res = a.x * b.y - a.y * b.x;
        return res;
    }

    // judge if vector ab to vector ac is counterClockWise
    // return == 0 if ab and ac is collinear
    // return > 0 if ab and ac counterClockWise
    // return < 0 if ab and ac is clockwise
    int counterClockWise(Point a, Point b, Point c) {
        Point p1(b.x - a.x, b.y - a.y), p2(c.x - a.x, c.y - a.y);
        return crossProduct(p1, p2);
    }

    int dist(Point a, Point b) {
        return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
    }
};

int main() {
    Solution s;
    vector<Point> points{Point(3, 0), Point(4, 0), Point(5, 0), Point(6, 1), Point(7, 2), Point(7, 3), Point(7, 4), Point(6, 5), Point(5, 5), Point(4, 5), Point(3, 5), Point(2, 5), Point(1, 4), Point(1, 3), Point(1, 2), Point(2, 1), Point(4, 2), Point(0, 3)};
    vector<Point> res = s.outerTrees(points);

    cout << res.size() << endl;
}
// 699. Falling Squares
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    struct Interval {
        int start, end, height;
        Interval(int s, int e, int h) : start(s), end(e), height(h) {}
    };

    int getHeight(vector<Interval>& intervals, Interval& cur) {
        int result = 0;
        for (Interval i : intervals) {
            if (i.end < cur.start || i.start > cur.end) continue;
            result = max(result, i.height);
        }
        cur.height += result;
        intervals.push_back(cur);
        return cur.height;
    }

    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        vector<Interval> intervals;
        vector<int> result;

        int h = 0;
        for (pair<int, int> p : positions) {
            Interval cur(p.first, p.second + p.first - 1, p.second);
            h = max(h, getHeight(intervals, cur));
            result.push_back(h);
        }

        return result;
    }
};
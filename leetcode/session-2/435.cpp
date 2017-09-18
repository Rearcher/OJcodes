// 435. Non-overlapping Intervals
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if (intervals.size() <= 1) return 0;

        sort(intervals.begin(), intervals.end(), [&](const Interval& a, const Interval& b) {
            return a.end < b.end;
        });

        int count = 1, end = intervals[0].end;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start >= end) {
                count += 1;
                end = intervals[i].end;
            }
        }

        return intervals.size() - count;
    }
};

int main() {

}
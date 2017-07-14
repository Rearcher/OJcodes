// 436. Find Right Interval
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> m;
        for (int i = 0; i < intervals.size(); ++i)
            m[intervals[i].start] = i;

        vector<int> result;
        for (int i = 0; i < intervals.size(); ++i) {
            auto iter = m.lower_bound(intervals[i].end);
            result.push_back(iter == m.end() ? -1 : iter->second);
        }

        return result;
    }
};

int main() {

}
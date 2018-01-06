// 630. Course Schedule II
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
        priority_queue<int> maxHeap;
        int cnt = 0;

        for (auto v : courses) {
            cnt += v[0];
            maxHeap.push(v[0]);
            if (cnt > v[1]) {
                cnt -= maxHeap.top();
                maxHeap.pop();
            }
        }

        return maxHeap.size();
    }
};

int main() {

}
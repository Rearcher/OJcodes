// 218. The Skyline Problem
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> height;
        for (auto v : buildings) {
            height.emplace_back(v[0], -v[2]);
            height.emplace_back(v[1], v[2]);
        }
        sort(height.begin(), height.end());

        multiset<int> heap;
        heap.insert(0);
        vector<pair<int, int>> result;
        int pre = 0, cur = 0;
        for (auto p : height) {
            if (p.second < 0) heap.insert(-p.second);
            else heap.erase(heap.find(p.second));

            cur = *heap.rbegin();
            if (cur != pre) {
                result.emplace_back(p.first, cur);
                pre = cur;
            }
        }

        return result;
    }
};

int main() {
    vector<vector<int>> buildings{{0, 2, 3}, {2, 5, 3}};
    Solution s;
    s.getSkyline(buildings);
}
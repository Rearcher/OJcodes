// 391. Perfect Rectangle
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if (rectangles.empty() || rectangles[0].empty()) return false;

        int x1, x2, y1, y2;
        x1 = y1 = INT_MAX;
        x2 = y2 = INT_MIN;

        unordered_set<string> hashSet;
        int area = 0;
        for (vector<int> v : rectangles) {
            x1 = min(x1, v[0]);
            y1 = min(y1, v[1]);
            x2 = max(x2, v[2]);
            y2 = max(y2, v[3]);

            area += (v[2] - v[0]) * (v[3] - v[1]);
            string key1 = to_string(v[0]) + " " + to_string(v[1]);
            string key2 = to_string(v[0]) + " " + to_string(v[3]);
            string key3 = to_string(v[2]) + " " + to_string(v[3]);
            string key4 = to_string(v[2]) + " " + to_string(v[1]);

            if (hashSet.count(key1)) hashSet.erase(key1); else hashSet.insert(key1);
            if (hashSet.count(key2)) hashSet.erase(key2); else hashSet.insert(key2);
            if (hashSet.count(key3)) hashSet.erase(key3); else hashSet.insert(key3);
            if (hashSet.count(key4)) hashSet.erase(key4); else hashSet.insert(key4);
        }
        if (!hashSet.count(to_string(x1) + " " + to_string(y1)) || !hashSet.count(to_string(x1) + " " + to_string(y2)) || 
            !hashSet.count(to_string(x2) + " " + to_string(y1)) || !hashSet.count(to_string(x2) + " " + to_string(y2)) || 
            hashSet.size() != 4)
            return false;

        return area == (x2 - x1) * (y2 - y1);
    }
};

int main() {

}
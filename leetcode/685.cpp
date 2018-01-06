// 685. Redundant Connection II
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> result{0, 0};
        unordered_map<int, int> m;
        vector<int> parent(2001);
        for (int i = 0; i < parent.size(); ++i) parent[i] = i;

        for (vector<int> v : edges) {
            int p = v[0], s = v[1];
            if (m.count(s)) {
                result = v;
                break;
            }

            if (m.count(p) && m[p] == s) {
                result = v;
                break;
            }

            int p1 = find(parent, v[0]), p2 = find(parent, v[1]);
            if (p1 == p2) {
                result = v;
                break;
            }

            m[s] = p;
            parent[p2] = p1;
        }
        return result;
    }

private:
    int find(vector<int>& parent, int i) {
        while (i != parent[i]) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }
};

int main() {
    Solution s;
    vector<vector<int>> edges{{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 5}};
    vector<int> result = s.findRedundantDirectedConnection(edges);
    for (auto i : result) cout << i << " ";
    cout << endl;
}
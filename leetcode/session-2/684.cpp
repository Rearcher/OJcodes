// 684. Redundant Connection
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(2001);
        for (int i = 0; i < parent.size(); ++i) parent[i] = i;

        for (vector<int> v : edges) {
            int p1 = find(parent, v[0]), p2 = find(parent, v[1]);
            if (p1 == p2) return v;

            parent[p1] = p2;
        }
        
        return vector<int>{0, 0};
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
    vector<int> result = s.findRedundantConnection(edges);
    cout << result[0] << " " << result[1] << endl;
}
// 743. Network Delay Time
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> adjMatrix(N, vector<int>(N, INT_MAX));
        for (auto v : times) adjMatrix[v[0]-1][v[1]-1] = v[2];

        vector<int> dist(N, INT_MAX);
        dist[--K] = 0;

        set<pair<int, int>> minHeap;
        minHeap.insert({0, K});
        while (!minHeap.empty()) {
            int u = (*minHeap.begin()).second;
            minHeap.erase(minHeap.begin());

            for (int i = 0; i < N; ++i) {
                if (adjMatrix[u][i] != INT_MAX && dist[i] > dist[u] + adjMatrix[u][i]) {
                    auto iter = minHeap.find({dist[i], i});
                    if (iter != minHeap.end()) minHeap.erase(iter);

                    dist[i] = dist[u] + adjMatrix[u][i];
                    minHeap.insert({dist[i], i});
                }
            }
        }

        int result = *max_element(dist.begin(), dist.end());
        return result == INT_MAX ? -1 : result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> times{{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    cout << s.networkDelayTime(times, 4, 2) << endl;
}
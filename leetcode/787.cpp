// 787. Cheapest Flights Within K Stops
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i <= K; ++i) {
            vector<int> temp(dist);
            for (auto e : flights) {
                if (dist[e[0]] != INT_MAX) {
                    temp[e[1]] = min(temp[e[1]], dist[e[0]] + e[2]);
                }
            }
            dist = temp;
        }      
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

int main() {
    Solution s;
    int n = 3;
    vector<vector<int>> flights{{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    cout << s.findCheapestPrice(n, flights, 0, 2, 1) << "\n";
}
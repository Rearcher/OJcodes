// 310. Minimum Height Trees
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) return vector<int>{0};

        unordered_map<int, set<int>> adjList;
        for (auto p : edges) {
            if (adjList.count(p.first)) adjList[p.first].insert(p.second);
            else adjList[p.first] = {p.second};

            if (adjList.count(p.second)) adjList[p.second].insert(p.first);
            else adjList[p.second] = {p.first};
        }

        vector<int> leaves;
        for (int i = 0; i < n; ++i) 
            if (adjList[i].size() == 1) leaves.push_back(i);

        while (n > 2) {
            n -= leaves.size();
            vector<int> newLeaves;

            for (int i : leaves) {
                int node = *(adjList[i].begin());
                adjList[node].erase(i);
                if (adjList[node].size() == 1) 
                    newLeaves.push_back(node);
            }
            leaves = newLeaves;
        }

        return leaves;
    }
};

int main() {

}
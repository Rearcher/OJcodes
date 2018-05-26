// 835. Image Overlap
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int N = A.size();
        vector<int> a, b;
        for (int i = 0; i < N * N; ++i) {
            if (A[i / N][i % N] == 1) a.push_back(i / N * 100 + i % N);
            if (B[i / N][i % N] == 1) b.push_back(i / N * 100 + i % N);
        }

        unordered_map<int, int> count;
        for (int i : a) for (int j : b) count[i - j]++;

        int res = 0;
        for (auto it : count) res = max(res, it.second);
        return res; 
    }
};
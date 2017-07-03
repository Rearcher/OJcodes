// 454. 4Sum II
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> cache;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B.size(); ++j) {
                int sum = A[i] + B[j];
                if (cache.count(sum)) {
                    cache[sum] += 1;
                } else {
                    cache[sum] = 1;
                }
            }
        }

        int result = 0;
        for (int i = 0; i < C.size(); ++i) {
            for (int j = 0; j < D.size(); ++j) {
                int target = -(C[i] + D[j]);
                if (cache.count(target)) {
                    result += cache[target];
                }
            }
        }

        return result;
    }
};

int main() {
    vector<int> A{1, 2}, B{-2, -1}, C{-1, 2}, D{0, 2};
    Solution s;
    cout << s.fourSumCount(A, B, C, D) << endl;
}
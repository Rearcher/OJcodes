// 861. Score After Flipping Matrix
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int nrow = A.size(), ncol = A[0].size();
        
        bool flag = false;
        for (int i = 0; i < nrow; ++i) {
            if (A[i][0] == 0) {
                flag = true;
                break;
            }
        }
        
        if (flag) {
            for (int i = 0; i < nrow; ++i) {
                if (A[i][0] == 1) {
                    for (int j = 0; j < ncol; ++j)
                        A[i][j] = 1 - A[i][j];
                }
                A[i][0] = 1;
            }
        }
        
        int exp = ncol - 1;
        long long res = nrow * pow(2, exp);
        for (int j = 1; j < ncol; ++j) {
            int cntOne = 0;
            for (int i = 0; i < nrow; ++i)
                if (A[i][j] == 1) cntOne += 1;
            cntOne = max(cntOne, nrow - cntOne);
            res += cntOne * pow(2, --exp);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> A{{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};
    cout << s.matrixScore(A) << "\n";
}
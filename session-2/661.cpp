// 661. Image Smoother
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int nrow = M.size();
        int ncol = nrow > 0 ? M[0].size() : 0;
        
        vector<vector<int>> result(nrow, vector<int>(ncol, 0));
        for (int i = 0; i < nrow; ++i)
            for (int j = 0; j < ncol; ++j)
                result[i][j] = sum(M, i, j, nrow, ncol);

        return result;
    }

private:
    int sum(vector<vector<int>>& M, int x, int y, int nrow, int ncol) {
        int res = 0, cnt = 0;
        for (int i = max(0, x-1); i <= min(x+1, nrow-1); ++i)
            for (int j = max(0, y-1); j <= min(y+1, ncol-1); ++j)
                res += M[i][j], cnt += 1;
        return res / cnt;
    }
};

int main() {
    Solution s;
    vector<vector<int>> M{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> res = s.imageSmoother(M);

    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j)
            cout << res[i][j] << " ";
        cout << "\n";
    }
}
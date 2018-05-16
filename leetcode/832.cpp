// 832. Flipping an Image
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        
        vector<vector<int>> res(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = m - 1; j >= 0; --j)
                res[i][m - 1 - j] = 1 - A[i][j]; 
        }
        return res;
    }
};
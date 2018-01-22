// 766. Toeplitz Matrix
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            int j = 0;
            int value = matrix[i][j];
            i += 1, j += 1;
            while (i < m && j < n) {
                if (matrix[i][j] != value) 
                    return false;
                i += 1, j += 1;
            }
        }

        for (int j = 1; j < n; ++j) {
            int i = 0;
            int value = matrix[i][j];
            i += 1, j += 1;
            while (i < m && j < n) {
                if (matrix[i][j] != value)
                    return false;
                i += 1, j += 1;
            }
        }
        return true;    
    }
};

int main() {
    // vector<vector<int>> matrix{{1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}};
    vector<vector<int>> matrix{{1, 2}, {2, 2}};
    Solution s;
    cout << s.isToeplitzMatrix(matrix) << endl;
}
// 566. Reshape the Matrix
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int nrow = nums.size();
        int ncol = nrow > 0 ? nums[0].size() : 0;
        if (nrow * ncol != r * c) {
            return nums;
        }

        vector<vector<int>> result(r, vector<int>(c));
        for (int i = 0; i < nrow; ++i) {
            for (int j = 0; j < ncol; ++j) {
                int cnt = i * ncol + j + 1;
                int new_i = (cnt % c == 0) ? (cnt / c - 1) : (cnt / c);
                int new_j = cnt - new_i * c - 1;
                result[new_i][new_j] = nums[i][j];
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> nums(2);
    nums[0] = vector<int>{1, 2};
    nums[1] = vector<int>{3, 4};
    
    vector<vector<int>> result = s.matrixReshape(nums, 4, 1);
    for (auto i : result) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}
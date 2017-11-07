// 723. Candy Crush
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int nrow = board.size(), ncol = board[0].size();
        bool flag = true;

        while (flag) {
            flag = false;
            for (int i = 0; i < nrow; ++i) {
                for (int j = 0; j + 2 < ncol; ++j) {
                    int v = abs(board[i][j]);
                    if (v != 0 && abs(board[i][j+1]) == v && abs(board[i][j+2]) == v) {
                        board[i][j] = board[i][j+1] = board[i][j+2] = -v;
                        flag = true;
                    }
                }
            }

            for (int i = 0; i + 2 < nrow; ++i) {
                for (int j = 0; j < ncol; ++j) {
                    int v = abs(board[i][j]);
                    if (v != 0 && abs(board[i+1][j]) == v && abs(board[i+2][j]) == v) {
                        board[i][j] = board[i+1][j] = board[i+2][j] = -v;
                        flag = true;
                    }
                }
            }

            for (int j = 0; j < ncol; ++j) {
                int t = nrow - 1;
                for (int i = nrow - 1; i >= 0; --i) {
                    if (board[i][j] > 0)
                        board[t--][j] = board[i][j];
                }
                while (t >= 0) board[t--][j] = 0;
            }
        }
        return board;
    }
};

int main() {
    Solution s;
    vector<vector<int>> board{{110,5,112,113,114},{210,211,5,213,214},{310,311,3,313,314},{410,411,412,5,414},{5,1,512,3,3},{610,4,1,613,614},{710,1,2,713,714},{810,1,2,1,1},{1,1,2,2,2},{4,1,4,4,1014}};
    vector<vector<int>> result = s.candyCrush(board);

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j)
            cout << result[i][j] << " ";
        cout << "\n";
    }
}

// 130. Surrounded Regions
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int nrow = board.size();
        if (!nrow) return;

        int ncol = board[0].size();
        for (int i = 0; i < nrow; ++i) {
            check(board, i, 0, nrow, ncol);
            if (ncol > 1) check(board, i, ncol - 1, nrow, ncol);
        }
        for (int j = 0; j < ncol; ++j) {
            check(board, 0, j, nrow, ncol);
            if (nrow > 1) check(board, nrow - 1, j, nrow, ncol);
        }

        for (int i = 0; i < nrow; ++i) {
            for (int j = 0; j < ncol; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'R') board[i][j] = 'O';
            }
        }

        return;
    }

private:
    void check(vector<vector<char>>& board, int i, int j, int nrow, int ncol) {
        if (board[i][j] != 'O') return;
        board[i][j] = 'R';
        if (i > 1) check(board, i - 1, j, nrow, ncol);
        if (j > 1) check(board, i, j - 1, nrow, ncol);
        if (i + 1 < nrow) check(board, i + 1, j, nrow, ncol);
        if (j + 1 < ncol) check(board, i, j + 1, nrow, ncol);
    }
};  

int main() {
    Solution s;
    vector<vector<char>> board{{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    // vector<vector<char>> board{{'O', 'O'}, {'O', 'O'}};
    s.solve(board);

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}
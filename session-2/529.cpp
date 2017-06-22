// 529. Minesweeper
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        int nrow = board.size(), ncol = nrow > 0 ? board[0].size() : 0;
        vector<vector<bool>> visited(nrow, vector<bool>(ncol, false));
        reveal(board, visited, click[0], click[1]);

        return board;
    }

private:
    int adjacentMines(vector<vector<char>>& board, int x, int y) {
        int cnt = 0;
        int nrow = board.size(), ncol = nrow > 0 ? board[0].size() : 0;
        for (int i = max(0, x-1); i <= min(x+1, nrow-1); ++i) {
            for (int j = max(0, y-1); j <= min(y+1, ncol-1); ++j)
                if (board[i][j] == 'M') cnt += 1;
        }
        return board[x][y] == 'M' ? cnt - 1 : cnt;
    }

    void reveal(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y) {
        int nrow = board.size(), ncol = nrow > 0 ? board[0].size() : 0;
        if (board[x][y] != 'E') return;

        int cnt = adjacentMines(board, x, y);
        visited[x][y] = true;

        if (cnt > 0) {
            board[x][y] = '0' + cnt;
            return;
        }

        board[x][y] = 'B';
        for (int i = x - 1; i <= x + 1; ++i) {
            for (int j = y - 1; j <= y + 1; ++j) {
                if (i < 0 || i >= nrow || j < 0 || j >= ncol) continue;
                if (i == x && j == y) continue;
                if (visited[i][j]) continue;
                reveal(board, visited, i, j);
            }
        }
    }
};

int main() {
    vector<vector<char>> board = {{'E', 'E', 'E', 'E', 'E'}, {'E', 'E', 'M', 'E', 'E'}, {'E', 'E', 'E', 'E', 'E'}, {'E', 'E', 'E', 'E', 'E'}};
    Solution s;
    
    vector<int> click{3, 0};
    s.updateBoard(board, click);

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++)
            cout << board[i][j];
        cout << "\n";
    }
}
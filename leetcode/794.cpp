// 794. Valid Tic-Tac-Toe State
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int cntX = 0, cntO = 0;
        string s = board[0] + board[1] + board[2];
        for (char c : s) {
            if (c == 'O') cntO++;
            else if (c == 'X') cntX++;
        }

        if (cntX != cntO && cntX != cntO + 1) 
            return false;

        bool xWin = false, oWin = false;
        isWin(s[0], s[4], s[8], xWin, oWin);
        isWin(s[6], s[4], s[2], xWin, oWin);
        for (int i = 0; i < 3; ++i) {
            isWin(s[i * 3], s[i * 3 + 1], s[i * 3 + 2], xWin, oWin);
            isWin(s[i], s[i + 3], s[i + 6], xWin, oWin);
        }

        if (xWin && oWin) return false;
        if (xWin && cntX != cntO + 1) return false;
        if (oWin && cntX != cntO) return false;

        return true;
    }

private:
    void isWin(char c1, char c2, char c3, bool& xWin, bool& oWin) {
        if (c1 == 'X' && c1 == c2 && c2 == c3) xWin = true;
        if (c1 == 'O' && c1 == c2 && c2 == c3) oWin = true;
        return;
    }  
};

int main() {
    Solution s;
    vector<string> board{"XOX", "O O", "XOX"};
    cout << s.validTicTacToe(board) << "\n";
}
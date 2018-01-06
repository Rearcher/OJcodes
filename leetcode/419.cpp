// 419. Battleships in a Board
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int result = 0;
        unordered_set<int> last, current;

        for (int i = 0; i < board.size(); ++i) {
            int j = 0;
            while (j < board[i].size()) {
                if (board[i][j] == '.') {
                    j++;
                    continue;
                } else {
                    int k = j + 1;
                    while (k < board[i].size() && board[i][k] == 'X')
                        k++;
                    if (k == j + 1) {
                        current.insert(k);
                    } else {
                        result += 1; 
                    }
                    j = k;
                }
            }

            for (const auto& pos : last) {
                if (current.count(pos) == 0) {
                    result += 1;
                }
            }

            last = unordered_set<int>(current);
            current.clear();
        }

        return result + last.size();
    }
};

int main() {
    Solution s;
    // vector<vector<char>> board = vector<vector<char>>{vector<char>{'X', '.', '.', 'X'},
                                                    //   vector<char>{'.', '.', '.', 'X'},
                                                    //   vector<char>{'.', '.', '.', 'X'}};
    vector<vector<char>> board = vector<vector<char>>{vector<char>{'.', '.'}, vector<char>{'X', 'X'}};
    cout << s.countBattleships(board) << endl;
}
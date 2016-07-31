// Valid Sudoku
public class Solution {
    private HashSet<Character> hashSet = new HashSet<>();
    
    private boolean checkRow(char[][] board, int row) {
        hashSet.clear();
        for (int i = 0; i < board[row].length; ++i) {
            if (board[row][i] == '.') continue;
            if (hashSet.contains(board[row][i])) return false;
            else hashSet.add(board[row][i]);
        }
        return true;
    }

    private boolean checkCol(char[][] board, int col) {
        hashSet.clear();
        for (int i = 0; i < board.length; ++i) {
            if (board[i][col] == '.') continue;
            if (hashSet.contains(board[i][col])) return false;
            else hashSet.add(board[i][col]);
        }
        return true;
    }

    private boolean checkSquare(char[][] board, int x, int y) {
        hashSet.clear();
        for (int i = x; i < x + 3; ++i) {
            for (int j = y; j < y + 3; ++j) {
                if (board[i][j] == '.') continue;
                if (hashSet.contains(board[i][j])) return false;
                else hashSet.add(board[i][j]);
            }
        }
        return true;
    }
    
    public boolean isValidSudoku(char[][] board) {
        for (int i = 0; i < board.length; ++i) {
            if (!checkRow(board, i)) return false;
            if (!checkCol(board, i)) return false;
        }

        for (int i = 0; i < board.length; i += 3)
            for (int j = 0; j < board[0].length; j += 3)
                if (!checkSquare(board, i, j)) return false;
        return true;
    }
}

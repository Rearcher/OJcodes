/**
 * Game of Life
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var gameOfLife = function(board) {
    var n = board.length;
    var m = board[0].length;
    
    var liveNeigbours = function(i, j) {
        var res = 0;
        for (var k = Math.max(0, i-1); k <= Math.min(n-1, i+1); k += 1) {
            for (var l = Math.max(0,j-1); l <= Math.min(m-1,j+1); l += 1) {
                res += board[k][l] & 1;
            }
        }
        res -= board[i][j] & 1;
        return res;
    }
    
    for (var i = 0; i < n; i += 1) {
        for (var j = 0; j < m; j += 1) {
            var lives = liveNeigbours(i,j);
            if (board[i][j] === 0 && lives === 3) {
                board[i][j] = 2;
            }
            
            if (board[i][j] === 1 && lives >= 2 && lives <= 3) {
                board[i][j] = 3;
            }
        }
    }
    
    for (i = 0; i < n; i += 1) {
        for (j = 0; j < m; j += 1) {
            board[i][j] >>>= 1;
        }
    }
};

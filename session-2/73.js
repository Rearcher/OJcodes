/**
 * set matrix zeroes
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function(matrix) {
    var rows = matrix.length;
    if (rows === 0) return;
    
    var cols = matrix[0].length;
    var col0 = 1;
    
    var i, j;
    for (i = 0; i < rows; i += 1) {
        if (matrix[i][0] === 0) {
            col0 = 0;
        }
        for (j = 1; j < cols; j += 1) {
            if (matrix[i][j] === 0) {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }
    
    for (i = rows - 1; i >= 0; i -= 1) {
        for (j = cols - 1; j >= 1; j -= 1) {
            if (matrix[i][0] === 0 || matrix[0][j] === 0) {
                matrix[i][j] = 0;
            }
        }
        if (col0 === 0) {
            matrix[i][0] = 0;
        }
    }
};

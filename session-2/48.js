/**
 * rotate image
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    var n = matrix.length;
    
    matrix.reverse();
    
    var swap = function(i, j) {
        var tmp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = tmp;
    }
    
    for (var i = 0; i < n; i += 1) {
        for (var j = i + 1; j < n; j += 1) {
            swap(i, j);
        }
    }
};

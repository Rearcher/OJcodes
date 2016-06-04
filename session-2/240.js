/**
 * search a 2D matrix
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    var n = matrix.length;
    if (n === 0) return false;
    var m = matrix[0].length;
    
    var i = n-1, j = 0;
    while (i >= 0 && j < m) {
        if (matrix[i][j] === target) {
            return true;
        } else if (matrix[i][j] > target) {
            i--;
        } else {
            j++;
        }
    }
    
    return false;
};

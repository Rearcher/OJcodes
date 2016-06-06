/**
 * search a 2D matrix
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    var n = matrix.length;
    var m = matrix[0].length;
    
    var begin = 0, end = n-1, mid;
    while (begin <= end) {
        mid = begin + Math.floor((end - begin) / 2);
        if (matrix[mid][0] === target) {
            return true;
        } else if (matrix[mid][0] > target) {
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }
    
    var i = Math.max(0, Math.min(begin, end));
    begin = 0;
    end = m - 1;
    while (begin <= end) {
        mid = begin + Math.floor((end - begin) / 2);
        if (matrix[i][mid] === target) {
            return true;
        } else if (matrix[i][mid] > target) {
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }
    
    return false;
}; 

/* unique path */
/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function(m, n) {
    var temp1 = m-1, temp2 = n-1;
    n = temp1 + temp2;
    m = Math.min(temp1, temp2);
    
    var res = 1;
    for (var i = 1; i <= m; i += 1) {
        res *= (n - m + i);
        res = Math.floor(res/i);
    }
    
    return res;
};

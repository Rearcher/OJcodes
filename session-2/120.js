/**
 * Triangle(bottom-up dp)
 * @param {number[][]} triangle
 * @return {number}
 */
var minimumTotal = function(triangle) {
    
    var n = triangle.length;
    var res = triangle[n-1].slice(0);
    
    for (var i = n - 2; i >= 0; i -= 1) {
        for (var j = 0; j <= n; j += 1) {
            res[j] = Math.min(res[j], res[j+1]) + triangle[i][j];
        }
    }
    
    return res[0];
};

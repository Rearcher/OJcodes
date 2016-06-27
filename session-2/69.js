/**
 * Sqrt(x) 
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
    
    if (!x) return x;
    
    var left = 1;
    var right = x;
    var res = 1;
    
    while (left <= right) {
        var mid = left+Math.floor((right-left)/2);
        if (mid * mid <= x) {
            res = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return res;
};

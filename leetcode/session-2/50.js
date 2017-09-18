/**
 * Pow(x, n)
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
    
    if (!n) return 1;
    
    var tmp = x;
    tmp = n > 0 ? myPow(x, Math.floor(n/2)) : myPow(x, Math.ceil(n/2));
    if (n%2 === 0) {
        return tmp * tmp;
    }
    
    if (n > 0) {
        return x * tmp * tmp;
    } else {
        return tmp * tmp / x;
    }
};

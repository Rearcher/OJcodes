// reverse integer
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    var isPositive = true;
    if (x < 0) {
        isPositive = false;
        x = -x;
    }
    
    var ans = 0, t;
    while (x !== 0) {
        t = x%10;
        ans = ans*10+t;
        x = (x-t)/10;
    }
    
    if (!isPositive) ans = -ans;
    if (ans > 2147483647 || ans < -2147483648) {
        return 0;
    }
    
    return ans;
};

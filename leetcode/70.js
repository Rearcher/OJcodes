// Climbing Stairs
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    if (n === 1) return 1;
    else if (n === 2) return 2;
    
    var f1 = 1, f2 = 2;
    var ans;
    for (var i = 3; i <= n; ++i) {
        ans = f1 + f2;
        f1 = f2;
        f2 = ans;
    }
    
    return ans;
};

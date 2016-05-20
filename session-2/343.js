/* integer break */
/**
 * @param {number} n
 * @return {number}
 */
var integerBreak = function(n) {
    if (n === 2) return 1;
    if (n === 3) return 2;
    
    var ans = 1;
    while (n > 4) {
        ans *= 3;
        n -= 3;
    }
    ans *= n;
    
    return ans;
};

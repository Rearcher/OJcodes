/**
 * Ugly Number II
 * @param {number} n
 * @return {number}
 */
var nthUglyNumber = function(n) {
    if (n === 1) return 1;
    
    var primes = [2, 3, 5];
    var index = [0, 0, 0];
    var res = [1];
    
    var min = Number.MAX_SAFE_INTEGER;
    for (var i = 1; i < n; i += 1) {
        min = Number.MAX_SAFE_INTEGER;
        for (var j = 0; j < 3; j += 1) {
            min = Math.min(res[index[j]]*primes[j], min);
        }
        res.push(min);
        
        for (j = 0; j < 3; j += 1) {
            if (min % primes[j] === 0) {
                index[j] += 1;
            }
        }
    }
    
    return res.pop();  
};

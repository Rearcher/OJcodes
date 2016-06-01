/**
 * super ugly number
 * @param {number} n
 * @param {number[]} primes
 * @return {number}
 */
var nthSuperUglyNumber = function(n, primes) {
    var len = primes.length;
    var index = [], i, j;
    var res = [1];
    
    for (i = 0; i < len; i += 1) {
        index.push(0);
    }
    
    var min = Math.MAX_SAFE_INTEGER;
    for (i = 1; i < n; i += 1) {
        min = Number.MAX_SAFE_INTEGER;
        for (j = 0; j < len; j += 1) {
            min = Math.min(min, res[index[j]] * primes[j]);
        }
        res.push(min);
        
        for (j = 0; j < len; j += 1) {
            if (min % primes[j] === 0) {
                index[j] += 1;
            }
        }
    }
    
    return res.pop();
};

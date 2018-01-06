/* combination sum III */
/**
 * @param {number} k
 * @param {number} n
 * @return {number[][]}
 */
function backtracking(res, singleRes, begin, curIndex, k, n, sum) {
    if (curIndex === k && sum === n) {
        res.push(singleRes.slice(0));
        return;
    }
    
    for (var i = begin; i <= 9; i += 1) {
        singleRes.push(i);
        backtracking(res, singleRes, i+1, curIndex+1, k, n, sum+i);
        singleRes.pop();
    }
}

 
var combinationSum3 = function(k, n) {
    var threshold = Math.floor((1+k)*k/2);
    if (n < threshold || k*9 <= n) return [];
    
    var res = [], singleRes = [];
    var top = Math.floor(n/k);
    backtracking(res, singleRes, 1, 0, k, n, 0);
    
    return res;
};

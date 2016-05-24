/* gray code */
/**
 * @param {number} n
 * @return {number[]}
 */
function backtracking(singleRes, res, n) {
    singleRes[n-1] = 1 - singleRes[n-1];
    res.push(parseInt(singleRes.join(''), 2));
    
    var idx = singleRes.lastIndexOf(1);
    if (idx-1 >= 0) {
        singleRes[idx-1] = 1 - singleRes[idx-1];
        res.push(parseInt(singleRes.join(''), 2));
        backtracking(singleRes, res, n);
    }
}
 
 
var grayCode = function(n) {
    if (!n) return [0];
    
    var singleRes = [], res = [];
    
    for (var i = 0; i < n; i++) {
        singleRes.push(0);
    }
    res.push(parseInt(singleRes.join(''), 2));
    
    
    backtracking(singleRes, res, n);
    
    return res;
};

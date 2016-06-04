/**
 * combine
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
var combine = function(n, k) {
    var singleRes = [];
    var res = [];
    
    var backtracking = function (begin, depth) {
        if (depth === k) {
            res.push(singleRes.slice(0));
            return;
        }
        
        for (var i = begin; i <= n; i += 1) {
            singleRes.push(i);
            backtracking(i+1, depth+1);
            singleRes.pop();
        }
    }
    
    backtracking(1, 0);
    
    return res;
};

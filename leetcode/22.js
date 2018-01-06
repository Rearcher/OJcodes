/* generate parentheses */
/**
 * @param {number} n
 * @return {string[]}
 */
function backtracking(res, singleRes, leftIn, rightIn, n) {
    if (leftIn > n || rightIn > n || leftIn < rightIn) 
        return;
    
    if (leftIn ==  n && leftIn == rightIn) {
        res.push(singleRes.join(''));
        return;
    }
    
    singleRes.push('(');
    backtracking(res, singleRes, leftIn+1, rightIn, n);
    singleRes.pop();
    
    singleRes.push(')');
    backtracking(res, singleRes, leftIn, rightIn+1, n);
    singleRes.pop();
}
 
var generateParenthesis = function(n) {
    var res = [];
    var singleRes = [];
    
    singleRes.push('(');
    var leftIn = 1, rightIn = 0;
    
    backtracking(res, singleRes, leftIn, rightIn, n);
    
    return res;
};

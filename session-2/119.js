// pascal's triangel II
/**
 * @param {number} rowIndex
 * @return {number[]}
 */
function fact(n) {
    if (n === 0) return 1;
    return n * fact(n-1);
} 
 
function comb(m, n) {
    return fact(m)/(fact(n)*fact(m-n));
}
 
var getRow = function(rowIndex) {
    var arr = [];
    for (var i = 0; i <= rowIndex/2; i++) {
        arr.push(comb(rowIndex, i));
    }
    
    var res = arr.slice(0);
    if (rowIndex > 0 && rowIndex%2 === 0) arr.pop();
    
    if (rowIndex > 0)
        return res.concat(arr.reverse());
    else
        return res;
};

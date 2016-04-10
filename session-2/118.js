// pascal's triangle
/**
 * @param {number} numRows
 * @return {number[][]}
 */
function nextRow(row) {
    var res = [1];
    if (row.length === 0) return res;
    
    for (var i = 0; i < row.length-1; i++) {
        res.push(row[i]+row[i+1]);
    }
    res.push(1);
    
    return res;
} 

var generate = function(numRows) {
    var ans = [];
    var singleRow = [];
    for (var i = 0; i < numRows; i++) {
        singleRow = nextRow(singleRow);
        ans.push(singleRow);
    }
    return ans;
};

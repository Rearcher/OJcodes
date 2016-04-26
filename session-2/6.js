// zigzag conversion
/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    if (numRows === 1 || s.length === 0) {
        return s;
    }
    
    var ans = '', i, j, index;
    for (i = 0; i < s.length && i < numRows; ++i) {
        index = i;
        ans += s[index];
        
        for (j = 1; index < s.length; ++j) {
            if (i === 0 || i === numRows-1) {
                index += 2*(numRows-1);
            } else {
                if (j%2 !== 0) {
                    index += 2*(numRows-i-1);
                } else {
                    index += 2*i;
                }
            }
            if (index < s.length) ans += s[index];
        }
    }
    
    return ans;
};

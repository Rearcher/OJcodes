// longest common prefix
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if (strs.length === 0) return String("");
    
    var ans = strs[0];
    for (var i = 1; i < strs.length; i++) {
        if (strs[i].length === 0) return String("");
        for (var j = 0; j < ans.length && j < strs[i].length && ans[j] === strs[i][j]; ++j);
        ans = ans.substring(0, j);
    }
    
    return ans;
};

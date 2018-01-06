// length of last word
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    var n = s.length;
    var pos = s.lastIndexOf(' ');
    
    if (n === 0) return 0;
    if (pos === -1) return n;
    if (pos === n-1) {
        var i = pos;
        while (--i >= 0 && s[i] === ' ');
        if (i < 0) return 0;
        
        var cnt = 1;
        while (--i >= 0 && s[i] !== ' ') {
            cnt++;
        }
        return cnt;
    }
    
    return n-pos-1;
};

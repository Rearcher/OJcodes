// reverse string
/**
 * @param {string} s
 * @return {string}
 */
var reverseString = function(s) {
    var res = [];
    for (var i = s.length-1; i >= 0; i -= 1) {
        res.push(s[i]);
    }
    return res.join('');
};

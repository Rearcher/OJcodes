// valid palindrome
/**
 * @param {string} s
 * @return {boolean}
 */
function test(s) {
    if (s.length <= 1) return true;
    var i = 0, j = s.length-1;
    
    while (i < j) {
        if (s[i++] !== s[j--]) return false;
    }
    
    return true;
}

var isPalindrome = function(s) {
    var t = "", i;
    s = s.toLowerCase();
    
    for (i = 0; i < s.length; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || 
        (s[i] >= '0' && s[i] <= '9')) {
            t += s[i];        
        }    
    }
    
    return test(t);
};

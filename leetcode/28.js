// implement strstr()
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    if (needle.length === 0) return 0;
    if (haystack.length === 0) return -1;
    
    var i, j;    
    for (i = 0; i < haystack.length; i++) {
        for (j = 0; j <= needle.length; j++) {
            if (j === needle.length) return i;
            if (i+j >= haystack.length) return -1;
            if (haystack[i+j] != needle[j]) break;
        }
    }
    
    return -1;
};

// power of four
/**
 * @param {number} num
 * @return {boolean}
 */
var isPowerOfFour = function(num) {
    if (num <= 0) return false;
    var ans = Math.log(num)/Math.log(4);
    if (Math.floor(ans) === ans) return true;
    
    return false;
};

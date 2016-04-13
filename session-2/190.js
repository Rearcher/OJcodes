// reverse bits
/**
 * @param {number} n - a positive integer
 * @return {number} - a positive integer
 */
var reverseBits = function(n) {
     var temp, ans = 0;
     for (var i = 31; i >= 0; i--) {
        temp = n & 1;
        n >>>= 1;
        ans |= (temp << i);
    }
	
	// signed convert to unsigned
    ans >>>= 0;
    return ans;
};

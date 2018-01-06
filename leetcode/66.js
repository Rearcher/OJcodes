// plus one
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    var len = digits.length;
    var carry = 0;
    
    digits[len-1] += 1;
    for (var i = len-1; i >= 0; --i) {
        digits[i] += carry;
        if (digits[i] >= 10) {
            carry = Math.floor(digits[i]/10);
            digits[i] = digits[i]%10;   
        }
        else carry = 0;
    }
    
    var tmp = [carry];
    if (carry === 0) return digits;
    else return tmp.concat(digits);
};

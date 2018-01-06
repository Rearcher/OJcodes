// palindrome number
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    var stringX = x.toString();
    var arrayX = Array.from(stringX);
    arrayX.reverse();
    var reverseX = arrayX.join('');
    
    return stringX === reverseX;
};

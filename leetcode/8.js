// string to integer(atoi)
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    var i = 0, ans = 0;
    var isPositive = true;
    
    for (; i < str.length && str[i] === ' '; ++i);
    if (i >= str.length) return ans;
    
    if (str[i] == '+') {
        isPositive = true;
        i++;
    } else if (str[i] == '-') {
        isPositive = false;
        i++;
    } else if (str[i] < '0' || str[i] > '9') {
        return ans;
    }
    
    while (i < str.length) {
        if (str[i] < '0' || str[i] > '9') {
            break;
        }
        ans = ans*10 + (str[i]-'0');
        i++;
    }
    if (!isPositive) ans = -ans;
    if (ans > 2147483647) {
        return 2147483647;
    } else if (ans < -2147483648) {
        return -2147483648;
    }
    
    return ans;
};

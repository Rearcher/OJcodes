// integer to roman
/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
    var convertions = [["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"],
                       ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"],
                       ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"],
                       ["", "M", "MM", "MMM"]];
    var ans = "";
    ans += convertions[3][Math.floor(num/1000)];
    ans += convertions[2][Math.floor(num%1000/100)];
    ans += convertions[1][Math.floor(num%100/10)];
    ans += convertions[0][Math.floor(num%10)];
    
    return ans;
};

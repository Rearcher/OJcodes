// roman to int
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    var convertions = [];
    convertions['M'] = 1000;
    convertions['D'] = 500;
    convertions['C'] = 100;
    convertions['L'] = 50;
    convertions['X'] = 10;
    convertions['V'] = 5;
    convertions['I'] = 1;
    
    var last_add = convertions[s[0]];
    var ans = last_add;
    for (var i = 1; i < s.length; i++) {
        if (convertions[s[i]] > last_add) {
            ans = ans - last_add * 2 + convertions[s[i]];
        } else {
            ans += convertions[s[i]];
        }
        last_add = convertions[s[i]];
    }
    
    return ans;
};

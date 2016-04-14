// count and say
/**
 * @param {number} n
 * @return {string}
 */
function getRes(str) {
    var res = "";
    if (str === "") return res;
    
    var i = 0, cnt;
    while (i < str.length) {
        cnt = 1;
        while (i+1 < str.length && str[i] === str[i+1]) {
            i++;
            cnt++;
        }
        res += cnt.toString();
        res += str[i].toString();
        i++;
    }
    
    return res;
}
 
var countAndSay = function(n) {
    var res = "1";
    
    if (n === 1) return res;
    for (var i = 2; i <= n; i++) {
        res = getRes(res);
    }
    
    return res;
};

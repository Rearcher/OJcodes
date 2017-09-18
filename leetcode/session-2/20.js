// valid parentheses
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    var stack = [];
    var tmp;
    
    for (c of s) {
        if (c === '(' || c === '{' || c === '[') {
            stack.push(c);
        } else if (c === ')' || c === '}' || c === ']' ) {
            if (stack.length === 0) return false;
            else {
                tmp = stack.pop();
                if ((c === ')' && tmp !== '(') || 
                (c === ']' && tmp !== '[') ||
                (c === '}' && tmp !== '{')) {
                    return false;            
                }
            }
        }
    }
    
    if (stack.length > 0) return false;
    
    return true;
};

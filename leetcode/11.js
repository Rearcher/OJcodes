/**
 * container with most water
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    var n = height.length;
    var res = (n-1) * Math.min(height[0], height[n-1]);
    
    var l = 0, r = n - 1;
    while (l < r) {
        if (height[l] < height[r]) {
            l++;
        } else {
            r--;
        }
        
        var tmp = (r-l) * Math.min(height[l], height[r]);
        if (tmp > res) {
            res = tmp;
        }
    }
    
    return res;
};

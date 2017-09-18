/**
 * Jump Game
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
    
    var len = nums.length;
    if (len === 1) return true;
    
    var curPos = 0;
    
    while (curPos < len) {
        if (nums[curPos] === 0) {
            return false;
        }
        
        var flag;
        var max = Number.MIN_SAFE_INTEGER;
        
        if (curPos + nums[curPos] + 1>= len) {
            return true;
        }
        
        for (var i = 1; i <= nums[curPos]; i += 1) {
            if (nums[curPos+i]+i > max) {
                max = nums[curPos+i] + i;
                flag = i;
            }    
        }
        
        curPos += flag;
    }
    
    return true;
};

/* maximum subarray */
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    if (nums.length === 0) return 0;
    
    var maxSoFar = nums[0], maxEndingHere = nums[0];
    for (var i = 1; i < nums.length; i += 1) {
        maxEndingHere = Math.max(maxEndingHere + nums[i], nums[i]);
        maxSoFar = Math.max(maxSoFar, maxEndingHere);
    }
    
    return maxSoFar;
};

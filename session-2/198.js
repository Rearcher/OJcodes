// House robber
/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    if (nums.length === 0) {
        return 0;
    }
    
    var dp = [nums[0]];
    var flag = 1;
    
    for (var i = 1; i < nums.length; i++){
        if (flag === 0) {
            dp[i] = dp[i-1] + nums[i];
            flag = 1;
        } else {
            if (i>=2 && dp[i-2]+nums[i] > dp[i-1]) {
                dp[i] = dp[i-2] + nums[i];
                flag = 1;
            } else if (nums[i] > nums[i-1]) {
                dp[i] = nums[i];
                flag = 1;
            } else {
                dp[i] = dp[i-1];
                flag = 0;
            }
        }
    }
    
    return dp.pop();
};

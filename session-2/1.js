// two sum
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var ans = [], i, j, t;
    var hashMap = [];
    
    for (i = 0; i < nums.length; ++i) {
        if (hashMap[target-nums[i]] !== undefined) {
            ans.push(i, hashMap[target-nums[i]]);
            return ans;
        }
        hashMap[nums[i]] = i;
    }
    
    return ans;
};

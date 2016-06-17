/**
 * Subsets
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
    
    var singleRes = [];
    var res = [];
    
    var backtracking = function (singleRes, res, depth, begin) {
        
        if (singleRes.length === depth) {
            res.push(singleRes.slice(0));
            return;
        }
        
        for (var i = begin; i < nums.length; i += 1) {
            singleRes.push(nums[i]);
            backtracking(singleRes, res, depth, i+1);
            singleRes.pop();
        }
        
    }
    
    for (var i = 0; i <= nums.length; i += 1) {
        backtracking(singleRes, res, i, 0);
    }
    
    return res;
};

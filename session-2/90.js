/**
 * subset II(with duplicates)
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsetsWithDup = function(nums) {
    var singleRes = []; 
    var res = []; 
    
    nums.sort();
    
    var backtracking = function (singleRes, res, begin) {
    
        res.push(singleRes.slice(0));
         
        for (var i = begin; i < nums.length; i += 1) {
            if (i === begin || nums[i] !== nums[i-1]) {
                singleRes.push(nums[i]);
                backtracking(singleRes, res, i+1);
                singleRes.pop();
            }
        }
    
    }   
    
    backtracking(singleRes, res, 0); 
    
    return res;

};

/**
 * Remove Duplicates from Sorted Array II
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    var len = nums.length;
    if (len <= 2) return len;
    
    var i = 0, j = 0, cnt, elem;
    while (j < len) {
        cnt = 1;
        elem = nums[j];
        while (++j < len && nums[j] === nums[j-1]) {
            cnt += 1;
        }
        
        if (cnt > 2) cnt = 2;
        while (cnt--) {
            nums[i++] = elem;
        }
    }
    
    return i;
};

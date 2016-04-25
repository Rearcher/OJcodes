// rotate array
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
    if (k === 0 || k === nums.length) return;
    var n = nums.length;
    k = k%n;
    
    var rotateStart = 0;
    var i, temp;
    for (; k !== 0; n -= k, rotateStart += k, k %= n) {
        for (i = rotateStart; i < rotateStart+k; ++i) {
            temp = nums[i];
            nums[i] = nums[n-k+i];
            nums[n-k+i] = temp;
        }
    }
};

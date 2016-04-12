// merge two sorted array
/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
    if (n === 0) return;
    var idx = m+n-1;
    var i = m-1, j = n-1;
    
    while (i >= 0 && j >= 0) {
        if (nums1[i] >= nums2[j]) {
            nums1[idx--] = nums1[i--];
        } else {
            nums1[idx--] = nums2[j--];
        }
    }
    
    while (i >= 0) {
        nums1[idx--] = nums1[i--];
    }
    while (j >= 0) {
        nums1[idx--] = nums2[j--];
    }
    
    return;
};

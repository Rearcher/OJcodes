/* intersection of two arrays */
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    var i = 0, j = 0;
    var hashMap = {}, res = new Set();
    while (i < nums1.length) {
        if (hashMap.hasOwnProperty(nums1[i])) {
            hashMap[nums1[i]] += 1;
        } else {
            hashMap[nums1[i]] = 1;
        }
        i++;
    }
    
    while (j < nums2.length) {
        if (hashMap.hasOwnProperty(nums2[j])
            && hashMap[nums2[j]] > 0) {
            res.add(nums2[j]);
            hashMap[nums2[j]] -= 1;
        }
        j++;
    }
    
    return Array.from(res);
};

/**
 * Kth Largest Element in an Array
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findKthLargest = function(nums, k) {
    
    var swap = function (i, j) {
        var tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    var maxHeapify = function (begin, end) {
        var father = begin;
        var son = father * 2 + 1;
    
        while (son < end) {
            if (son + 1 < end && nums[son + 1] > nums[son]) {
                son += 1;
            }  
            
            if (nums[father] >= nums[son]) {
                return;
            } else {
                swap(father, son);
                father = son;
                son = father * 2 + 1;
            }
        }
    }
    
    var n = nums.length;
    for (var i = Math.floor(n/2); i >= 0; i -= 1) {
        maxHeapify(i, n);
    }
    
    k -= 1;
    for (i = n - 1; i > 0 && k > 0; i -= 1, k -= 1) {
        swap(0, i);
        maxHeapify(0, i);
    }
    
    return nums[0];
};

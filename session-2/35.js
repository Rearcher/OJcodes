/* search insert position */
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    var low = 0, high = nums.length-1;
    while (low < high) {
        var mid = low + Math.floor((high - low) / 2);
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) {
            high = mid - 1;   
        } else {
            low = mid + 1;
        }
    }
    if (nums[low] == target) return low;
    else if (nums[low] > target) return low;
    else return low+1;
};

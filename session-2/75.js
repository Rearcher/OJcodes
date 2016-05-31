/* sort colors */
var sortColors = function(nums) {
    var lo = 0, hi = nums.length - 1;
    var i = 0;
    
    var swap = function (i, j) {
        var tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    while (i <= hi) {
        if (nums[i] < 1) {
            swap(lo++, i++);
        } else if (nums[i] > 1) {
            swap(i, hi--);
        } else {
            i++;
        }
    }
    
    return;
};

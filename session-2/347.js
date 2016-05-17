// top k frequent elements
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
function swap(arr, i, j) {
    var temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

function data(spec) {
    var that = {};
    that.num = spec.num;
    that.cnt = spec.cnt;
    
    return that;
} 
 
var topKFrequent = function(nums, k) {
    var hashTable = {}, i, datas = [];
    for (i = 0; i < nums.length; i += 1) {
        if (hashTable.hasOwnProperty(nums[i])) {
            hashTable[nums[i]] += 1;
        } else {
            hashTable[nums[i]] = 1;
        }
    }
    
    for (var key in hashTable) {
        if (hashTable.hasOwnProperty(key)) {
            datas.push({num: key, cnt: hashTable[key]});
        }
    }
    
    var maxHeapify = function(start, end) {
        var father = start, son = father * 2 + 1;
        while (son < end) {
            if (son + 1 < end && datas[son].cnt < datas[son+1].cnt) {
                son += 1;
            }
        
            if (datas[father].cnt >= datas[son].cnt) {
                return;
            } else {
                swap(datas, father, son);
                father = son;
                son = father * 2 + 1;
            }
        }
    }
    
    
    var n = datas.length;
    for (i = Math.floor(n/2); i >= 0; i -= 1) {
        maxHeapify(i, n);
    }
    
    var res = [];
    for (i = 0; i < k; i += 1) {
        res.push(+datas[0].num);
        swap(datas, 0, n-1-i);
        maxHeapify(0, n-1-i);
    }
    
    return res;
};

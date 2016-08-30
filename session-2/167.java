// Two Sum II - Input array is sorted
public class Solution {
    private int binarySearch(int[] numbers, int target) {
        int lo = 0, hi = numbers.length - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (numbers[mid] == target) return mid;
            else if (numbers[mid] > target) hi = mid - 1;
            else lo = mid + 1;
        }
        return -1;
    }
    
    public int[] twoSum(int[] numbers, int target) {
        for (int i = 0; i < numbers.length; ++i) {
            if (numbers[i] * 2 == target && i + 1 < numbers.length && numbers[i] == numbers[i+1]) {
                return new int[]{i+1, i+2};
            }
            int idx = binarySearch(numbers, target - numbers[i]);
            if (idx != -1) return new int[]{i+1, idx+1};
        }
        return new int[]{};
    } 
}

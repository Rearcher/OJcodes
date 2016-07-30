// H-Index II
// version 2
public class Solution {
    public int hIndex(int[] citations) {
        int n = citations.length;
        if (n == 0) return 0;

        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int paperNums = n - mid;
            if (citations[mid] >= paperNums) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return n - low;
    }
}

// version 1
public class Solution {
    public int hIndex(int[] citations) {
        int n = citations.length;
        if (n == 0) return 0;

        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int paperNums = n - mid;
            if (citations[mid] >= paperNums) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
    
        return Math.min(n - low, citations[low]);
    }
}

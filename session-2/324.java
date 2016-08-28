// Wiggle Sort
public class Solution {
   private boolean less(int v, int w) {
        return v < w;
    }

    private void exch(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    private int partition(int[] a, int lo, int hi) {
        int i = lo, j = hi + 1;
        while (true) {
            while (i < hi && less(a[++i], a[lo]));
            while (j > lo && less(a[lo], a[--j]));
            if (i >= j) break;
            exch(a, i, j);
        }
        exch(a, lo, j);
        return j;
    }

    public int findKthElement(int[] nums, int k) {
        k = nums.length - k;
        int lo = 0, hi = nums.length - 1;
        while (lo < hi) {
            int j = partition(nums, lo, hi);
            if (j < k) {
                lo = j + 1;
            } else if (j > k) {
                hi = j - 1;
            } else {
                break;
            }
        }
        return nums[k];
    }

    public void wiggleSort(int[] nums) {
        int median = findKthElement(nums, (nums.length + 1) / 2);
        int n = nums.length;

        int left = 0, i = 0, right = n - 1;
        while (i <= right) {
            // elements larger than median are put into the first odd slots
            if (nums[newIndex(i, n)] > median) {
                exch(nums, newIndex(left++, n), newIndex(i++, n));
            // elements smaller than median are put into the last even slots
            } else if (nums[newIndex(i, n)] < median) {
                exch(nums, newIndex(right--, n), newIndex(i, n));
            } else {
                i++;
            }
        }
    }
    
    public int newIndex(int idx, int n) {
        return (1 + idx * 2) % (n | 1);
    }

}

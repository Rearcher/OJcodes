/* 4. Median of Two Sorted Arrays, O(log(min(m,n))) 
 * two sorted arrays: nums1, nums2
 * ____________________________________________________________________________________________________
 *                        |           left part                 |             right part               |
 * cut nums1 at position i| nums1[0], nums1[1], ..., nums1[i-1] | nums1[i], nums1[i+1], ..., nums1[m-1]|
 * cut nums2 at position j| nums2[0], nums2[1], ..., nums2[j-1] | nums2[j], nums2[j+1], ..., nums2[n-1]|
 *
 * if we can ensure:
 * 1) len(left_part) == len(right_part)
 * 2) max(left_part) <= min(right_part)
 * then the answer is (max(left_part) + min(right_part))/2;
 *
 * 1) i+j == m-i+n-j(m+n is even) or i+j == m-i+n-j+1(m+n is odd)
 *    if (n >= m) j = (m + n + 1)/2 - i, because if n < m, j might be negative
 * 2) nums1[i-1] <= nums2[j] && nums2[j-1] <= nums1[i]
 *
 * so, we just binary search i satisfies the two conditions above
 * one more thing, when i = 0 or j = 0, the left part of nums1 or nums2 is empty
 *                 when i = m or j = n, the right part of nums1 or nums2 is empty
 */
public class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        if (m > n) {
            int[] temp = nums1;
            nums1 = nums2;
            nums2 = temp;

            m = nums1.length;
            n = nums2.length;
        }

        int lo = 0, hi = m, half = (m + n + 1) / 2;
        while (lo <= hi) {
            int i = (lo + hi) / 2;
            int j = half - i;
            if (j > 0 && i < m && nums2[j - 1] > nums1[i])
                lo = i + 1;
            else if (i > 0 && j < n && nums1[i - 1] > nums2[j])
                hi = i - 1;
            else {
                int maxLeft, minRight;
                if (i == 0) maxLeft = nums2[j - 1];
                else if (j == 0) maxLeft = nums1[i - 1];
                else maxLeft = Math.max(nums1[i - 1], nums2[j - 1]);

                if ((m + n) % 2 == 1)
                    return maxLeft;

                if (i == m) minRight = nums2[j];
                else if (j == n) minRight = nums1[i];
                else minRight = Math.min(nums1[i], nums2[j]);

                return (maxLeft + minRight) / 2.0;
            }
        }

        return 0.0;
    }
}

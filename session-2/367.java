// 367. Valid Perfect Square
public class Solution {
    public boolean isPerfectSquare(int num) {
        int low = 1, high = num;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int temp = num / mid;
            if (temp == mid && num % mid == 0) {
                return true;
            } else if (temp > mid) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
}

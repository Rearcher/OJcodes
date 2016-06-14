// H-index
public class Solution {
    
	public int hIndex(int[] citations) {
        int length = citations.length;
        if (length == 0) {
            return 0;
        }
        
        int[] arr = new int[length + 1];
        for (int i = 0; i < length; i += 1) {
            if (citations[i] > length) {
                arr[length] += 1;
            } else {
                arr[citations[i]] += 1;
            }
        }
        
        int t = 0;
        for (int i = length; i >= 0; i -= 1) {
            t += arr[i];
            if (t >= i) {
                return i;
            }
        }
        
        return 0;
    }
}

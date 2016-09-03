// Russian Doll Envelopes
public class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        int rows = envelopes.length;
        Arrays.sort(envelopes, (o1, o2) -> {
            if (o1[0] == o2[0])
                return o2[1] - o1[1];
            else 
                return o1[0] - o2[0];
        });
        
		// Longest Increasing Subsequences
        int dp[] = new int[envelopes.length];
        int len = 0;
        for (int[] envelope : envelopes) {
            int index = Arrays.binarySearch(dp, 0, len, envelope[1]);
            if (index < 0) index = -(index + 1);
            dp[index] = envelope[1];
            
            if (index == len) len++;
        }
        
        return len;
    }
}

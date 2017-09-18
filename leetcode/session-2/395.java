// 395. Longest Substring with At Least K Repeating Characters
public class Solution {
    private int findMinCnt(String t) {
        int[] cnt = new int[26];
        for (int i = 0; i < t.length(); ++i)
            cnt[t.charAt(i) - 'a']++;

        int min = Integer.MAX_VALUE;
        for (int i = 0; i < 26; ++i)
            if (cnt[i] > 0 && cnt[i] < min)
                min = cnt[i];

        return min;
    }

    public int longestSubstring(String s, int k) {
        int n = s.length();
        for (int len = n; len >= k; --len) {
            for (int start = 0; start <= n - len; ++start) {
                if (findMinCnt(s.substring(start, start+len)) >= k)
                    return len;
            }
        }
        return 0;
    }
}

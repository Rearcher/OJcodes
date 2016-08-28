// Find the Difference
public class Solution {
    public char findTheDifference(String s, String t) {
        char ans = 'a';
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i)
            cnt[s.charAt(i) - 'a']++;
        
        for (int i = 0; i < t.length(); ++i) {
            if (cnt[t.charAt(i) - 'a'] == 0) 
                ans = t.charAt(i);
            else if (cnt[t.charAt(i) - 'a'] > 0) {
                cnt[t.charAt(i) - 'a']--;
            }
        }
        return ans;
    }
}

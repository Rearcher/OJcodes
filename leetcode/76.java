/*
 * 76. Minimum Window Substring
 */ 
public class Solution {
    public String minWindow(String s, String t) {
        String res = "";
        if (s.length() < t.length()) return res;

        HashMap<Character, Integer> hashMap = new HashMap<>(), map = new HashMap<>();
        for (int i = 0; i < t.length(); ++i) {
            char c = t.charAt(i);
            if (hashMap.containsKey(c)) hashMap.put(c, hashMap.get(c)+1);
            else hashMap.put(c, 1);
        }

        int left = 0, right = 0, cnt = 0;
        while (right < s.length()) {
            char cLeft = s.charAt(left);
            char cRight = s.charAt(right);

            if (cnt == t.length()) {
                while (!map.containsKey(cLeft)) {
                    left++;
                    cLeft = s.charAt(left);
                }
                String temp = s.substring(left, right);
                if (res == "" || res.length() > temp.length())
                    res = temp;

                left++;
                if (hashMap.containsKey(cLeft)) {
                    map.put(cLeft, map.get(cLeft) - 1);
                    if (map.get(cLeft) < hashMap.get(cLeft)) cnt--;
                }
            } else if (cnt < t.length()) {
                right++;
                if (hashMap.containsKey(cRight)) {
                    if (map.containsKey(cRight)) map.put(cRight, map.get(cRight)+1);
                    else map.put(cRight, 1);

                    if (map.get(cRight) <= hashMap.get(cRight)) cnt++;
                }
            }
        }

        if (cnt < t.length()) return res;
        while (cnt == t.length()) {
            char cLeft = s.charAt(left);
            if (map.containsKey(cLeft)) {
                map.put(cLeft, map.get(cLeft)-1);
                if (map.get(cLeft) < hashMap.get(cLeft))
                    break;
            }
            left++;
        }
        String temp = s.substring(left, right);
        res = (res == "" || res.length() > temp.length()) ? temp : res;
        return res;
    }
}

/*
 * 30. Substring with Concatenation of All Words
 * sliding window solution
 */ 
public class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> res = new ArrayList<>();
        if (words.length == 0 || s.length() < words.length * words[0].length())
            return res;
        HashMap<String, Integer> hashMap = new HashMap<>(), curMap = new HashMap<>();
        for (String word : words) {
            if (!hashMap.containsKey(word)) hashMap.put(word, 1);
            else hashMap.put(word, hashMap.get(word)+1);
        }

        int wordLength = words[0].length();
        String str = null, tmp = null;
        for (int i = 0; i < wordLength; ++i) {
            int cnt = 0;
            for (int left = i, right = i; right + wordLength <= s.length(); right += wordLength) {
                str = s.substring(right, right + wordLength);
                if (hashMap.containsKey(str)) {
                    if (curMap.containsKey(str)) curMap.put(str, curMap.get(str)+1);
                    else curMap.put(str, 1);

                    if (curMap.get(str) <= hashMap.get(str)) cnt++;
                    while (curMap.get(str) > hashMap.get(str)) {
                        tmp = s.substring(left, left + wordLength);
                        curMap.put(tmp, curMap.get(tmp)-1);
                        left += wordLength;
                        if (curMap.get(tmp) < hashMap.get(tmp)) cnt--;
                    }
                    if (cnt == words.length) {
                        res.add(left);
                        tmp = s.substring(left, left + wordLength);
                        curMap.put(tmp, curMap.get(tmp)-1);
                        left += wordLength;
                        cnt--;
                    }
                } else {
                    curMap.clear();
                    cnt = 0;
                    left = right + wordLength;
                }
            }
            curMap.clear();
        }

        return res;
    }
}

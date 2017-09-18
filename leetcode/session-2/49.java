// Group Anagrams
public class Solution {
    private String transform(String str) {
        char[] chars = new char[str.length()];
        str.getChars(0, str.length(), chars, 0);
        Arrays.sort(chars);
        return new String(chars);
    }

    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> res = new ArrayList<>();
        Map<String, Integer> hashMap = new HashMap<>();
        int idx = 0;

        for (String str : strs) {
            String temp = transform(str);
            if (hashMap.containsKey(temp)) {
                res.get(hashMap.get(temp)).add(str);
            } else {
                res.add(new ArrayList<>());
                res.get(idx).add(str);
                hashMap.put(temp, idx);
                idx++;
            }
        }
        return res;
    }
}

// reverse vowels of a string
public class Solution {
    public String reverseVowels(String s) {
        int i = 0, j = s.length() - 1;
        char[] chars = new char[j+1];
        s.getChars(0, j+1, chars, 0);
        while (i < j) {
            while (i < j && chars[i] != 'a' && chars[i] != 'e' && chars[i] != 'i' && chars[i] != 'o' && chars[i] != 'u' &&
                            chars[i] != 'A' && chars[i] != 'E' && chars[i] != 'I' && chars[i] != 'O' && chars[i] != 'U')
                i++;
            while (i < j && chars[j] != 'a' && chars[j] != 'e' && chars[j] != 'i' && chars[j] != 'o' && chars[j] != 'u' &&
                            chars[j] != 'A' && chars[j] != 'E' && chars[j] != 'I' && chars[j] != 'O' && chars[j] != 'U')
                j--;
            if (i < j) {
                char temp = chars[i];
                chars[i] = chars[j];
                chars[j] = temp;
                i++;
                j--;
            }
        }
        return new String(chars);
    }
}

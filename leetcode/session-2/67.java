// Add Binary
public class Solution {
    public String addBinary(String a, String b) {
        String aa = new StringBuffer(a).reverse().toString();
        String bb = new StringBuffer(b).reverse().toString();
        
        StringBuilder res = new StringBuilder();
        int carry = 0, i;
        for (i = 0; i < aa.length() && i < bb.length(); ++i) {
            int num1 = aa.charAt(i) - '0';
            int num2 = bb.charAt(i) - '0';
            res.append((num1 + num2 + carry) % 2);
            carry = (num1 + num2 + carry) / 2;
        }
        
        while (i < aa.length()) {
            int num = aa.charAt(i) - '0';
            res.append((num + carry) % 2);
            carry = (num + carry) / 2;
            i++;
        }
        
        while (i < bb.length()) {
            int num = bb.charAt(i) - '0';
            res.append((num + carry) % 2);
            carry = (num + carry) / 2;
            i++;
        }
        if (carry > 0) res.append(1);
        return res.reverse().toString();
    }
}

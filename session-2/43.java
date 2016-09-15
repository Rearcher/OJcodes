/*
 * 43. Multiply Strings
 */
public class Solution {
    private StringBuilder multiplyOneDigit(String num1, char digit) {
        StringBuilder res = new StringBuilder();
        int carry = 0;
        for (int i = num1.length() - 1; i >= 0; --i) {
            int digit1 = num1.charAt(i) - '0';
            int digit2 = digit - '0';
            int product = digit1 * digit2 + carry;
            res.insert(0, (char) (product % 10 + '0'));
            carry = product / 10;
        }
        if (carry > 0) res.insert(0, (char) (carry + '0'));

        return res;
    }

    private StringBuilder add(String num1, String num2) {
        StringBuilder res = new StringBuilder();
        int i = num1.length() - 1, j = num2.length() - 1;
        int carry = 0;

        while (i >= 0 && j >= 0) {
            int digit1 = num1.charAt(i) - '0';
            int digit2 = num2.charAt(j) - '0';
            int sum = digit1 + digit2 + carry;
            res.insert(0, (char) (sum % 10 + '0'));
            carry = sum / 10;
            i--; j--;
        }

        while (i >= 0) {
            int sum = (num1.charAt(i) - '0') + carry;
            res.insert(0, (char) (sum % 10 + '0'));
            carry = sum / 10;
            i--;
        }

        while (j >= 0) {
            int sum = (num2.charAt(j) - '0') + carry;
            res.insert(0, (char) (sum % 10 + '0'));
            carry = sum / 10;
            j--;
        }

        if (carry > 0) res.insert(0, (char) (carry + '0'));

        return res;
    }

    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) return "0";
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < num2.length(); ++i) {
            if (res.length() == 0) {
                res = multiplyOneDigit(num1, num2.charAt(i));
            } else {
                res.append('0');
                res = add(res.toString(), multiplyOneDigit(num1, num2.charAt(i)).toString());
            }
        }

        return res.toString();
    }
}

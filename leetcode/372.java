// Super Pow
public class Solution {
    public int quickMod(int a, int b, int c) {
        int ans = 1;
        a = a % c;
        while (b > 0) {
            if (b % 2 == 1) {
                ans = (ans * a) % c;
            }
            b /= 2;
            a = (a * a) % c;
        }
        return ans;
    }

    public int superPow(int a, int[] b) {
        int ans = 1;
        for (int i = 0; i < b.length; ++i) {
            if (i == 0) ans = quickMod(a, b[0], 1337);
            else ans = quickMod(ans, 10, 1337) * quickMod(a, b[i], 1337) % 1337;
        }
        return ans;
    }
}

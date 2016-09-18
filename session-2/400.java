/*
 * 400. Nth Digit
 */
public class Solution {
    public int findNthDigit(int n) {
        long numBits = 1;
        long numCnts = 9;
        long base = 1;

        long product = numBits * numCnts;
        while (n > product) {
            n -= product;
            numBits += 1;
            numCnts *= 10;
            base *= 10;
            product = numBits * numCnts;
        }

        long offset = n / numBits;
        long digitOffset = n % numBits;
        long number = base + (digitOffset > 0 ? offset + 1 : offset) - 1;
        if (numBits == 1) return (int)number;

        long res = 0;
        long cirCnt = digitOffset == 0 ? 0 : numBits - digitOffset;
        for (int i = 0; i <= cirCnt; ++i) {
            res = number % 10;
            number /= 10;
        }
        return (int)res;
    }
}

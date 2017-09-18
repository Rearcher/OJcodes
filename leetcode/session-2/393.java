// 393. UTF-8 Validation
public class Solution {

    private boolean beginValid(int num) {
        num >>= 6;
        return num == 2;
    }

    private int isValid(int[] data, int begin) {
        if (begin > data.length) return begin;
        int n = 0, temp;

        while ((temp = data[begin] & 128) == 128) {
            n++;
            data[begin] <<= 1;
        }

        if (n == 0) return begin + 1;
        else if (n == 1) return -1;
        else {
            if (begin + n > data.length) return -1;
            for (int i = begin + 1; i < begin + n; ++i)
                if (!beginValid(data[i])) return -1;
        }
        return begin + n;
    }

    public boolean validUtf8(int[] data) {
        if (data.length == 0) return true;
        int idx, begin = 0;

        while ((idx = isValid(data, begin)) < data.length) {
            if (idx == -1) return false;
            begin = idx;
        }

        return true;
    }
}

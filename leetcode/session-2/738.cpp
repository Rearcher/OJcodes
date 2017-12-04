// 738. Monotone Increasing Digits
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        vector<int> digits;
        int n = N;
        while (N > 0) {
            digits.push_back(N % 10);
            N /= 10;
        }

        int i = digits.size() - 1;
        while (i - 1 >= 0 && digits[i] <= digits[i - 1]) {
            i--;
        }
        if (i == 0) return n;
        
        int k = i;
        while (true) {
            if (k == digits.size() - 1 || digits[k] - 1 >= digits[k + 1]) break;
            k++;
        }

        int result = 0;
        for (int j = digits.size() - 1; j > k; --j)
            result = result * 10 + digits[j];
        result = result * 10 + digits[k] - 1;
        for (int j = k - 1; j >= 0; --j)
            result = result * 10 + 9;
        return result;
    }
};

int main() {
    Solution s;
    cout << s.monotoneIncreasingDigits(10) << endl;
    cout << s.monotoneIncreasingDigits(1234) << endl;
    cout << s.monotoneIncreasingDigits(332) << endl;
    cout << s.monotoneIncreasingDigits(120) << endl;
}
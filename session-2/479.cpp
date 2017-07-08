// 479. Largest Palindrome Product
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;

        int top = (int)pow(10, n) - 1;
        int bottom = (int)pow(10, n - 1);

        long long maxNumber = (long long)top * (long long)top;
        int leftHalf = (int)(maxNumber / (long)pow(10, n));

        bool found = false;
        long long palindrome = 0;
        while (!found) {
            palindrome = create(leftHalf);

            for (long long i = top; i >= bottom; --i) {
                if (palindrome / i > maxNumber || i * i < palindrome) {
                    break;
                }

                if (palindrome % i == 0) {
                    found = true;
                    break;
                }
            }

            leftHalf--;
        }

        return palindrome % 1337;
    }

private:
    long long create(int leftHalf) {
        string leftStr = to_string(leftHalf);
        string rightStr = leftStr;
        reverse(rightStr.begin(), rightStr.end());
        cout << leftStr + rightStr << endl;
        return stol(leftStr + rightStr);
    }
};

int main() {
    Solution s;
    cout << s.largestPalindrome(5) << endl;
}  
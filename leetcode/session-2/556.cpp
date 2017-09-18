// 556. Next Greater Element II
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        reverse(digits.begin(), digits.end());

        int i = digits.size() - 1;
        while (i > 0 && digits[i-1] >= digits[i]) i--;
        if (i == 0) return -1;

        int num = digits[i-1], minIndex = i;
        for (int j = i + 1; j < digits.size(); ++j) 
            if (digits[j] > num && digits[j] < digits[minIndex]) 
                minIndex = j;
        swap(digits[i-1], digits[minIndex]);
        sort(digits.begin() + i, digits.end());
        
        long long result = 0;
        for (int d : digits) 
            result = result * 10 + d;

        return result > INT_MAX ? -1 : result;
    }
};

int main() {
    Solution s;
    cout << s.nextGreaterElement(1999999999) << endl;
}
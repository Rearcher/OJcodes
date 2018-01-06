// 728. Self Dividing Numbers
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int x = left; x <= right; ++x) {
            int n = x;
            bool flag = true;
            while (n > 0) {
                int digit = n % 10;
                if (digit == 0 || x % digit) {
                    flag = false;
                    break;
                }
                n /= 10;
            }

            if (flag) result.push_back(x);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> result = s.selfDividingNumbers(1, 22);
    for (auto a : result)
        cout << a << " ";
}
// 600. Non-negative Integers without Consecutive Ones
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findIntegers(int num) {
        int n = 0, temp = num;
        while (temp) {
            n += 1;
            temp >>= 1;
        }

        vector<int> a(n, 1), b(n, 1);
        for (int i = 1; i < n; ++i) {
            a[i] = a[i-1] + b[i-1];
            b[i] = a[i-1];
        }
        
        int result = a.back() + b.back();
        for (int i = n - 2; i >= 0; --i) {
            if (((num>>(i+1))&1)==1 && ((num>>i)&1)==1) break;
            if (((num>>(i+1))&1)==0 && ((num>>i)&1)==0) result -= b[i];
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.findIntegers(8) << endl;
}
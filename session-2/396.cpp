// 396. Rotate Function
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int sum = 0, F = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum += A[i];
            F += i * A[i];
        }

        int result = F;
        for (int i = A.size() - 1; i >= 1; --i) {
            F = F + sum - A.size() * A[i];
            result = max(result, F);
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> A{4, 3, 2, 6};
    cout << s.maxRotateFunction(A) << endl;
}
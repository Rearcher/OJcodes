// 413. Arithmetic Slices
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int begin = 0, end = 1, result = 0;
        while (end < A.size()) {
            while (end + 1 < A.size() && A[end] - A[end-1] == A[end+1] - A[end])
                end++;

            result += getNumber(end - begin + 1);
            begin = end;
            end = begin + 1;
        }
        return result;
    }

private:
    int getNumber(int length) {
        if (length < 3) return 0;
        return (int)(1.0 * length * length / 2 - 1.5 * length + 1);
    }
};

int main() {
    Solution s;
    vector<int> A{1, 2, 3, 4};
    cout << s.numberOfArithmeticSlices(A) << endl;
}
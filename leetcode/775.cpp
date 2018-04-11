// 775. Global and Local Inversions
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int localCnt = 0;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i - 1] > A[i]) localCnt++;
        }
        int globalCnt = countGlobalInversion(A, 0, A.size() - 1);
        return localCnt == globalCnt;
    }

private:
    int countGlobalInversion(vector<int>& A, int begin, int end) {
        if (begin >= end) return 0;

        int mid = begin + (end - begin) / 2;
        int x = countGlobalInversion(A, begin, mid);
        int y = countGlobalInversion(A, mid + 1, end);
        int z = 0;

        vector<int> temp(A.begin(), A.end());
        int i = begin, j = mid + 1;
        for (int k = begin; k <= end; ++k) {
            if (i > mid) A[k] = temp[j++];
            else if (j > end) A[k] = temp[i++];
            else if (temp[i] > temp[j]) {
                A[k] = temp[j++];
                z += mid - i + 1;
            } else A[k] = temp[i++];
        }

        return x + y + z;
    }
};

int main() {
    Solution s;
    vector<int> A{0, 3, 1, 2};
    cout << s.isIdealPermutation(A) << "\n";
}
// 801. Minimum Swaps To Make Sequences Increasing
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();

        // op代表直到当前位置采取不交换和交换的最少交换次数
        // op[0]表示在当前位置不交换，op[1]表示在当前位置交换
        // pre代表上一个位置的结果
        vector<int> op{0, 1}, pre{0, 1};

        for (int i = 1; i < n; ++i) {
            op = vector<int> {n, n};

            // 如果当前位置已经有序
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
                // 当前位置不交换
                op[0] = min(op[0], pre[0]);
                // 当前位置交换，上一个位置也要交换
                op[1] = min(op[1], pre[1] + 1);
            }

            // 如果当前位置交换后有序
            if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
                // 在上一个位置交换，当前位置不用交换
                op[0] = min(op[0], pre[1]);
                // 当前位置交换，上一个位置不用交换
                op[1] = min(op[1], pre[0] + 1);
            }

            pre = op;
        }

        return min(op[0], op[1]);
    }
};

int main() {
    Solution s;
    vector<int> A{1, 3, 5, 4};
    vector<int> B{1, 2, 3, 7};
    cout << s.minSwap(A, B) << endl;
}
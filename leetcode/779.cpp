// 779. K-th Symbol in Grammar
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int kthGrammar(int N, int K) {
        vector<int> idx(N + 1, -1);
        for (int i = N; i >= 1; --i) {
            idx[i] = K;
            K = (K + 1) / 2;
        }

        int last = 0;
        for (int i = 2; i <= N; ++i) {
            if (idx[i] == idx[i - 1] * 2) {
                last = (last == 0) ? 1 : 0;
            } else {
                last = (last == 0) ? 0 : 1;
            }
        }
        return last;    
    }
};

int main() {
    Solution s;
    cout << s.kthGrammar(4, 8) << "\n";
}
// #hard
// #array #O(n) #subarray #greedy
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int res = 0, cur = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (i >= K && A[i - K] > 1) {
                cur -= 1;
                A[i - K] -= 2;
            }
            
            if (cur % 2 == A[i]) {
                if (i + K - 1 >= A.size()) return -1;
                cur += 1;
                res += 1;
                A[i] += 2;
            }
        }
        return res;
    }
};
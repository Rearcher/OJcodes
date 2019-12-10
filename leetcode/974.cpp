// #medium
// #array #hash #prefixSum #subarray #O(n)
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> cnt(K, 0);
        cnt[0] = 1;
        
        int pre = 0, res = 0;
        for (int i = 0; i < A.size(); ++i) {
            pre = (pre + A[i] % K + K) % K;
            res += cnt[pre];
            cnt[pre] += 1;
        }
        
        return res;
    }
};
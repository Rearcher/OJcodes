// #medium
// #array #presum #subarray #O(n) 
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> p(A.begin(), A.end());
        for (int i = 1; i < p.size(); ++i) {
            p[i] += p[i - 1];
        }
        
        int res = p[L + M - 1], lmax = p[L - 1], mmax = p[M - 1];
        for (int i = L + M; i < p.size(); ++i) {
            lmax = max(lmax, p[i - M] - p[i - M - L]);
            mmax = max(mmax, p[i - L] - p[i - M - L]);
            res = max(res, max(lmax + p[i] - p[i - M], mmax + p[i] - p[i - L]));
        }
        
        return res;
    }
};
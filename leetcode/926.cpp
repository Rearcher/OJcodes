// #medium
// #array #O(n)
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int total = count(S.begin(), S.end(), '1');
        int len = S.size(), cur = 0, res = S.size();
        
        for (int i = 0; i < len; ++i) {
            res = min(res, cur + (len - i - total + cur));
            if (S[i] == '1') cur++;
        }
        res = min(res, total);
        
        return res;
    }
};
// #medium
// #dfs #backtracking
class Solution {
public:
    void dfs(int N, int K, int cur, int step, vector<int>& res) {
        if (step >= N) {
            res.push_back(cur);
            return;
        }
        
        if (step == 0) {
            for (int i = 1; i <= 9; ++i)
                dfs(N, K, i, step + 1, res);
        } else {
            int digit = cur % 10;
            if (digit - K >= 0)
                dfs(N, K, cur * 10 + digit - K, step + 1, res);
            if (digit + K <= 9 && K != 0)
                dfs(N, K, cur * 10 + digit + K, step + 1, res);
        }
    }
    
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> res;
        dfs(N, K, 0, 0, res);
        
        if (N == 1) res.push_back(0);
        return res;
    }
};
// 830. Positions of Large Groups
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        int i = 0;
        
        while (i < S.size()) {
            int j = i;
            while (j < S.size() && S[j] == S[i])
                j++;
            if (j - i >= 3) {
                res.push_back(vector<int>{i, j - 1});
            }
            i = j;
        }
        return res;
    }
};
// 691. Stickers to Spell Word
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int m = stickers.size();
        vector<vector<int>> cnt(m, vector<int>(26, 0));
        unordered_map<string, int> dp;

        for (int i = 0; i < m; ++i)
            for (char c : stickers[i]) 
                cnt[i][c-'a']++;
        dp[""] = 0;

        return helper(dp, cnt, target);
    }

private:
    int helper(unordered_map<string, int>& dp, vector<vector<int>>& cnt, string target) {
        if (dp.count(target)) return dp[target];

        int ans = INT_MAX, n = cnt.size();
        vector<int> tar(26, 0);
        for (char c : target) tar[c-'a']++;

        for (int i = 0; i < n; ++i) {
            if (cnt[i][target[0]-'a'] == 0) continue;

            string s;
            for (int j = 0; j < 26; ++j)
                if (tar[j] - cnt[i][j] > 0) 
                    s += string(tar[j] - cnt[i][j], 'a' + j);

            if (s.size() != target.size()) {
                int tmp = helper(dp, cnt, s);
                if (tmp != -1) ans = min(ans, 1 + tmp);
            }
        }

        dp[target] = ans == INT_MAX ? -1 : ans;
        return dp[target];
    }
};

int main() {
    vector<string> stickers{"control","heart","interest","stream","sentence","soil","wonder","them","month","slip","table","miss","boat","speak","figure","no","perhaps","twenty","throw","rich","capital","save","method","store","meant","life","oil","string","song","food","am","who","fat","if","put","path","come","grow","box","great","word","object","stead","common","fresh","the","operate","where","road","mean"};
    Solution s;
    cout << s.minStickers(stickers, "stoodcrease") << endl;
}
// 403. Frog Jump
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones.empty()) return false;
        if (stones.size() == 1) return true;
        if (stones[1] != 1) return false;
        if (stones.size() == 2) return true;
        
        unordered_set<int> st;
        for (int i = 0; i < stones.size(); ++i) {
            if (i > 3 && stones[i] > stones[i-1] * 2) return false;
            st.insert(stones[i]);
        }

        return dfs(st, stones[stones.size()-1], 1, 1);
    }

private:
    bool dfs(unordered_set<int>& stones, int target, int pos, int jump) {
        if (pos + jump - 1 == target || pos + jump == target || pos + jump + 1 == target)
            return true;

        if (stones.count(pos + jump + 1) && dfs(stones, target, pos + jump + 1, jump + 1))
            return true;
        if (stones.count(pos + jump) && dfs(stones, target, pos + jump, jump))
            return true;
        if (jump > 1 && stones.count(pos + jump - 1) && dfs(stones, target, pos + jump - 1, jump - 1))
            return true;

        return false;
    }
};

int main() {
    Solution s;
    vector<int> stones{0,1,2,3,4,8,9,11};
    cout << s.canCross(stones) << endl;
}
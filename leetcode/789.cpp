// 789. Escape The Ghosts
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int target_dist = abs(target[0]) + abs(target[1]);
        for (auto v : ghosts)
            if (abs(v[0] - target[0]) + abs(v[1] - target[1]) <= target_dist) 
                return false;
        return true;
    }
};
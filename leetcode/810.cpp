// 810. Chalkboard XOR Game
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i)
            res ^= nums[i];
        return res == 0 || nums.size() % 2 == 0;      
    }
};
// 462. Minimum Moves to Equal Array Elements II
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int result = 0;
        auto iter = nums.begin() + nums.size() / 2;
        nth_element(nums.begin(), iter, nums.end());

        int median = *iter;
        for (auto& num : nums) 
            result += abs(num - median);
        return result;
    }
};

int main() {

}
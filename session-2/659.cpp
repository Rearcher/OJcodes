// 659. Split Array into Consecutive Subsequences
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, mark;
        
        for (int i : nums) freq[i] += 1;
        for (int i : nums) {
            if (freq[i] == 0) continue;
            
            if (mark[i] > 0) {
                mark[i] -= 1;
                mark[i+1] += 1;
            } else if (freq[i+1] > 0 && freq[i+2] > 0) {
                freq[i+1] -= 1;
                freq[i+2] -= 1;
                mark[i+3] += 1;
            } else {
                return false;
            }
            freq[i] -= 1;
        }

        return true;
    }
};

int main() {

}
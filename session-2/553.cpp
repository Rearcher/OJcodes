// 553. Optimal Division
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string result = "";
        if (nums.empty()) return result;

        result += to_string(nums[0]);
        if (nums.size() == 1) return result;
        if (nums.size() == 2) {
            result += "/" + to_string(nums[1]);
            return result;
        }

        result += "/(" + to_string(nums[1]);
        for (int i = 2; i < nums.size(); ++i)
            result += "/" + to_string(nums[i]);
        result += ")";

        return result; 
    }
};

int main() {

}
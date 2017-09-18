// 384. Shuffle an Array
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }

    vector<int> reset() {
        return nums;
    }

    vector<int> shuffle() {
        vector<int> result(nums);
        for (int i = 0; i < result.size(); ++i) {
            int pos = rand() % (result.size() - i);
            swap(result[i+pos], result[i]);
        }
        return result;
    }

private:
    vector<int> nums;
};  

int main() {

}
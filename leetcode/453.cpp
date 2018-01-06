// 453. Minimum Moves to Equal Array Elements
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        // sum + num_of_moves * (len - 1) = x * len, 
        // where x denotes the final equal element in this array, and x = min_n + num_of_moves,
        // so, num_of_moves = sum - min_n * len;
        int min_n = INT_MAX, sum = 0, len = nums.size();
        for (int n : nums) {
            min_n = min(n, min_n);
            sum += n;
        }

        return sum - min_n * len;
    }
};

int main() {
    Solution s;
    vector<int> nums{1, 1, INT_MAX};
    cout << s.minMoves(nums) << endl;
}
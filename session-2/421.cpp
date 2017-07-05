// 421. Maximum XOR of Two Numbers in an Array
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max = 0, mask = 0;
        unordered_set<int> t;

        for (int i = 31; i >= 0; --i) {
            // consider the most significant bits
            // start from the most siginificant bit, find whether there are two different bits
            mask |= (1 << i);
            t.clear();

            for (int num : nums) {
                t.insert(num & mask);
            }

            // ideally, there are two different bits, so new_max = max | (1 << i)
            // so, if there are two different bits, there are two prefix in set, say A and B, A ^ B = new_max
            // while A ^ new_max = B, new_max ^ B = A
            int target = max | (1 << i);
            for (int prefix : t) {
                if (t.find(prefix ^ target) != t.end()) {
                    max = target;
                    break;
                }
            }
        }

        return max;
    }
};

int main() {
    Solution s;
    vector<int> nums{4, 6, 7};
    cout << s.findMaximumXOR(nums) << endl;
}
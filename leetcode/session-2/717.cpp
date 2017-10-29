// 717. 1-bit and 2-bit Characters
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0, n = bits.size();
        bool result = false;

        while (i < n) {
            if (bits[i] == 1) {
                i += 2;
                result = false;
            } else {
                i++;
                result = true;
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> bits{1, 1, 1, 0};
    cout << s.isOneBitCharacter(bits) << endl;
}
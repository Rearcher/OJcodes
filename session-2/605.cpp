// 605. Can Place Flowers
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i] == 0) {
                bool left_empty = (i == 0) || (i > 0 && flowerbed[i-1] == 0);
                bool right_empty = (i + 1 >= flowerbed.size()) || (i + 1 < flowerbed.size() && flowerbed[i+1] == 0);
                if (left_empty && right_empty) {
                    flowerbed[i] = 1;
                    n -= 1;
                }
            }
        }
        return n <= 0;
    }
};

int main() {
    Solution s;
    vector<int> flowerbed{1, 0, 0, 0, 1, 0, 0};
    cout << s.canPlaceFlowers(flowerbed, 2) << endl;    
}
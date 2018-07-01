// 860. Lemonade Change
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5 = 0, cnt10 = 0;
        for (int bill : bills) {
            if (bill == 5) {
                cnt5 += 1;
            } else if (bill == 10) {
                if (cnt5 <= 0) return false;
                cnt5 -= 1;
                cnt10 += 1;
            } else if (bill == 20) {
                if (cnt10 <= 0 && cnt5 < 3) return false;
                if (cnt10 > 0 && cnt5 <= 0) return false;
                
                if (cnt10 > 0) {
                    cnt10 -= 1;
                    cnt5 -= 1;
                } else {
                    cnt5 -= 3;
                }
            }
        }
        return true;
    }
};
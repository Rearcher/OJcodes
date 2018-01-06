// 657. Judge Route Circle
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int cnt1 = 0, cnt2 = 0;
        for (char c : moves) {
            switch (c) {
                case 'U':
                    cnt1 += 1;
                    break;
                case 'D':
                    cnt1 -= 1;
                    break;
                case 'L':
                    cnt2 += 1;
                    break;
                case 'R':
                    cnt2 -= 1;
            }
        }
        return cnt1 == 0 && cnt2 == 0;
    }
};

int main() {

}
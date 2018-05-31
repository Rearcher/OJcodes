// 780. Reaching Points
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx > ty) {
                if (ty == sy) return (tx - sx) % ty == 0;
                tx %= ty;
            } else {
                if (tx == sx) return (ty - sy) % tx == 0;
                ty %= tx;
            }
        }
        return false;
    }
};
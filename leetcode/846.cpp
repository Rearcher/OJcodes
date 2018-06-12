// 846. Hand of Straights
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int n = hand.size();
        if (n % W) return false;

        map<int, int> cnt;
        for (int card : hand) cnt[card] += 1;

        while (cnt.size()) {
            int start = cnt.begin()->first;
            if (--cnt[start] == 0) cnt.erase(start);

            for (int i = 1; i < W; ++i) {
                if (cnt.count(++start)) {
                    if (--cnt[start] == 0)
                        cnt.erase(start);
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> hand{1, 2, 3, 4, 5};

    cout << s.isNStraightHand(hand, 4) << "\n";
}
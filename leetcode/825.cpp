// 825. Friends Of Appropriate Ages
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int> cnt;
        for (int age : ages) cnt[age]++;

        int res = 0;
        for (auto a : cnt)
            for (auto b : cnt)
                if (request(a.first, b.first))
                    res += a.second * (b.second - (a.first == b.first ? 1 : 0));
        return res;
    }

private:
    bool request(int a, int b) {
        return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
    }
};
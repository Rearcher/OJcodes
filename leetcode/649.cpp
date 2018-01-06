// 649. Dota2 Senate
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        set<int> radiantIndex, direIndex;
        for (int i = 0; i < senate.size(); ++i) {
            if (senate[i] == 'R') radiantIndex.insert(i);
            else direIndex.insert(i);
        }

        while (true) {
            for (int i = 0; i < senate.size(); ++i) {
                if (radiantIndex.empty() || direIndex.empty()) break;
                if (senate[i] == 'R' && radiantIndex.count(i)) {
                    auto iter = direIndex.upper_bound(i);
                    direIndex.erase(iter == direIndex.end() ? direIndex.begin() : iter);
                } else if (senate[i] == 'D' && direIndex.count(i)) {
                    auto iter = radiantIndex.upper_bound(i);
                    radiantIndex.erase(iter == radiantIndex.end() ? radiantIndex.begin() : iter);
                }
            }
            if (radiantIndex.empty() || direIndex.empty()) break;
        }

        if (radiantIndex.empty()) return "Dire";
        return "Radiant";
    }
};

int main() {
    Solution s;
    cout << s.predictPartyVictory("RDD") << endl;
}
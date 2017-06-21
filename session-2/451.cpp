// 451. Sort Characters By Frequency
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        vector<string> bucket(s.size() + 1, "");
        string result;

        for (char c : s) cnt[c]++;
        for (auto& iter : cnt) {
            bucket[iter.second].append(iter.second, iter.first);
        }
        for (int i = s.size(); i > 0; --i) {
            if (!bucket[i].empty())
                result.append(bucket[i]);
        }

        return result;
    }
};

int main() {
    Solution s;
    cout << s.frequencySort("Aabb") << endl;
}
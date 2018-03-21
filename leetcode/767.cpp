// 767. Reorganize String
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> cnt;
        for (char c : S) {
            cnt[c] += 1;
            if (cnt[c] > (S.size() + 1) / 2)
                return "";
        }

        auto cmp = [](pair<char, int> a, pair<char, int> b) {
            return a.second < b.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
        for (auto it = cnt.begin(); it != cnt.end(); ++it)
            pq.emplace(it->first, it->second);

        string result;
        while (pq.size()) {
            pair<char, int> p1 = pq.top();
            pq.pop();

            if (result.empty() || result.back() != p1.first) {
                result.push_back(p1.first);
                if (p1.second - 1 > 0)
                    pq.emplace(p1.first, p1.second - 1);
            } else {
                pair<char, int> p2 = pq.top();
                pq.pop();
                result.push_back(p2.first);
                if (p2.second - 1 > 0)
                    pq.emplace(p2.first, p2.second - 1);
                pq.push(p1);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.reorganizeString("aaab") << endl;
}
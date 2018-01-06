// 692. Top K Frequent Words
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for (string s : words) cnt[s]++;

        auto cmp = [&](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> heap(cmp);
        
        for (auto iter : cnt) {
            heap.emplace(iter.first, iter.second);
            if (heap.size() > k) heap.pop();
        }

        vector<string> result;
        while (!heap.empty()) {
            result.insert(result.begin(), heap.top().first);
            heap.pop();
        }
        return result;
    }
};

int main() {
    Solution s;
    // vector<string> words{"i", "love", "leetcode", "i", "love", "coding"};
    vector<string> words{"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    vector<string> result = s.topKFrequent(words, 4);
    for (auto s : result) cout << s << " ";
    cout << "\n";
}
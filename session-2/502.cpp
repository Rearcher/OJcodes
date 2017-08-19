// 502. IPO
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<int> low;
        multiset<pair<int, int>> high;

        for (int i = 0; i < Profits.size(); ++i) {
            if (Profits[i] > 0) {
                if (Capital[i] <= W) low.push(Profits[i]);
                else high.emplace(Capital[i], Profits[i]);
            }
        }

        while (k-- && low.size()) {
            W += low.top();
            low.pop();

            for (auto iter = high.begin(); high.size() && iter->first <= W; iter = high.erase(iter))
                low.push(iter->second);
        }

        return W;
    }
};

int main() {
    vector<int> p{1, 2, 3};
    vector<int> c{0, 1, 1};
    Solution s;
    cout << s.findMaximizedCapital(2, 0, p, c) << endl;
}
// 526. Beautiful Arrangement
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int countArrangement(int N) {
        unordered_set<int> s;
        for (int i = 1; i <= N; ++i)
            s.insert(i);

        int result = 0;
        helper(s, 1, result);

        return result;
    }

private:
    void helper(unordered_set<int>& s, int pos, int& cnt) {
        if (s.empty()) {
            cnt += 1;
            return;
        }

        unordered_set<int> copy(s);
        for (const auto& number : copy) {
            if (number % pos == 0 || pos % number == 0) {
                s.erase(number);
                helper(s, pos + 1, cnt);
                s.insert(number);
            }
        }
    }
};

int main() {
    Solution s;
    cout << s.countArrangement(3) << endl;
}
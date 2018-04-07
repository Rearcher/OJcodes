// 781. Rabbits in Forest
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> cnt;
        int result = 0;

        for (int num : answers) {
            if (num == 0) {
                result += 1;
                continue;
            }
            cnt[num] += 1;
            if (cnt[num] == num + 1) {
                result += num + 1;
                cnt.erase(num);
            }
        }

        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
            result += it->first + 1;
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> answers{1, 0, 1, 0, 1};
    cout << s.numRabbits(answers) << "\n";
}
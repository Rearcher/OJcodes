// 316. Remove Duplicate Letters
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(256, 0);
        vector<bool> visited(256, false);
        for (char c : s) cnt[c]++;
        
        string result = "0";
        for (char c : s) {
            cnt[c]--;
            if (visited[c]) continue;
            while (c < result.back() && cnt[result.back()]) {
                visited[result.back()] = false;
                result.pop_back();
            }
            result.push_back(c);
            visited[c] = true;
        }

        return result.substr(1);
    }
};

int main() {
    Solution s;
    cout << s.removeDuplicateLetters("cbacdcbc");
}
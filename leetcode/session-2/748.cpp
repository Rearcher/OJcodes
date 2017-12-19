// 748. Shortest Completing Word
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> cnt(26, 0);
        for (char c : licensePlate) {
            if (c >= 'A' && c <= 'Z')
                c += 32;
            if (c >= 'a' && c <= 'z')
                cnt[c - 'a']++;
        }

        vector<pair<string, int>> arr(words.size());
        for (int i = 0; i < words.size(); ++i)
            arr[i] = {words[i], i};
        sort(arr.begin(), arr.end(), [&](pair<string, int>& a, pair<string, int>& b){ return a.first.size() < b.first.size(); });
        
        pair<string, int> result = {"", -1};
        for (auto w : arr) {
            vector<int> tmp(26, 0);
            for (char c : w.first) {
                if (c >= 'A' && c <= 'Z')
                    c += 32;
                if (c >= 'a' && c <= 'z')
                    tmp[c - 'a']++;
            }

            bool flag = true;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > tmp[i]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                if (result.first == "") {
                    result = w;
                    continue;
                }

                if (result.first.size() == w.first.size() && result.second > w.second) {
                    result = w;
                    continue;
                }

                if (result.first.size() < w.first.size()) break;
            }
        }

        return result.first;
    }
};

int main() {
    Solution s;
    string licensePlate = "1s3 PSt";
    vector<string> words{"step", "steps", "stripe", "stepple"};
    cout << s.shortestCompletingWord(licensePlate, words) << endl;
}
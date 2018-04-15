// 819. Most Common Word
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bans;
        for (auto s : banned) bans.insert(s);

        unordered_map<string, int> cnt;
        int maxCnt = 0;
        string res = "";

        stringstream ss(paragraph);
        string temp;
        while (ss >> temp) {
            char c = temp.back();
            if (c == ',' || c == '.' || c == '!' || c == '?' || c == ';' || c == '\'') {
                temp.pop_back();
            }
            for (int i = 0; i < temp.size(); ++i)
                if (temp[i] >= 'A' && temp[i] <= 'Z')
                    temp[i] += 32;
            if (bans.count(temp)) continue;

            cnt[temp] += 1;
            if (cnt[temp] > maxCnt) {
                maxCnt = cnt[temp];
                res = temp;
            }
        }     
        return res;   
    }
};

int main() {
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned{"hit"};
    Solution s;
    cout << s.mostCommonWord(paragraph, banned) << "\n";
}
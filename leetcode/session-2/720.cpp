// 720. Longest Word in Dictionary
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> s;
        for (string word : words) s.insert(word);

        sort(words.begin(), words.end(), [&](string a, string b){
            if (a.size() == b.size()) return a < b;
            else return a.size() > b.size();
        });
        for (string word : words) {
            bool flag = true;
            for (int len = 1; len <= words.size(); ++len) {
                if (!s.count(word.substr(0, len))) {
                    flag = false;
                    break;
                }
            }
            if (flag) return word;
        }
        return "";
    }
};

int main() {
    Solution s;
    // vector<string> words{"w","wo","wor","worl", "world"};
    // vector<string> words{"a", "banana", "app", "appl", "ap", "apply", "apple"};
    vector<string> words{"rac","rs","ra","on","r","otif","o","onpdu","rsf","rs","ot","oti","racy","onpd"};
    cout << s.longestWord(words) << endl;
}
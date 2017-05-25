// 500. Keyboard Row
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string keys[] = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM"};
        unordered_map<char, int> map;
        for (int i = 0; i < 3; ++i) {
            for (auto c : keys[i]) {
                map[c] = i;
            }
        }

        vector<string> result;
        for (auto word : words) {
            int idx = -1;
            for (auto c : word) {
                if (idx == -1) {
                    idx = map[c];
                } else if (idx != map[c]) {
                    idx = -1;
                    break;
                }
            }
            if (idx != -1) {
                result.push_back(word);
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<string> words = vector<string>{"Hello", "Alaska", "Dad", "Peace"};
    vector<string> result = s.findWords(words);
    for (auto word : result)
        cout << word << " ";
    cout << "\n";
}
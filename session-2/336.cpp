// 336. Palindrome Pairs
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> m;
        for (int i = 0; i < words.size(); ++i)
            m[words[i]] = i;

        vector<vector<int>> result;
        for (int j = 0; j < words.size(); ++j) {
            string word = words[j];
            for (int i = 1; i <= word.size(); ++i) {
                string left = word.substr(0, i);
                string right = word.substr(i);

                if (isPalindrome(left)) {
                    string target(right);
                    reverse(target.begin(), target.end());
                    if (m.count(target) && m[target] != j)
                        result.push_back({m[target], j});
                }

                if (isPalindrome(right)) {
                    string target(left);
                    reverse(target.begin(), target.end());
                    if (m.count(target) && m[target] != j && right.size()) 
                        result.push_back({j, m[target]});
                }
            }
        }

        return result;
    }

private:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
};

int main() {

}
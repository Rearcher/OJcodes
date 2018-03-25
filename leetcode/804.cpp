// 804. Unique Morse Code Words
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;       

        for (string word : words) {
            string tmp;
            for (char c : word)
                tmp += morse[c - 'a'];
            s.insert(tmp);
        }

        return s.size();
    }
};

// 722. Remove Comments
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> result;
        string line = "";
        bool isBlock = false;

        for (string s : source) {
            for (int i = 0; i < s.size();) {
                if (isBlock) {
                    if (i + 1 == s.size()) i++;
                    else {
                        if (s.substr(i, 2) == "*/") isBlock = false, i += 2;
                        else i++;
                    }
                } else {
                    if (i + 1 == s.size()) line.push_back(s[i++]);
                    else {
                        string m = s.substr(i, 2);
                        if (m == "/*") isBlock = true, i += 2;
                        else if (m == "//") break;
                        else line.push_back(s[i++]);
                    }
                }
            }
            if (!line.empty() && !isBlock) result.push_back(line), line = "";
        }
        return result;
    }
};
// 591. Tag Validator
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool isValid(string code) {
        int i = 0;
        return validTag(code, i) && i == code.size();
    }

private:
    bool validCData(string s, int& i) {
        if (s.find("<![CDATA[", i) != i) return false;
        int j = s.find("]]>", i);
        if (j == string::npos) return false;
        i = j + 3;
        return true;        
    }

    bool validText(string s, int& i) {
        int j = i;
        while (i < s.size() && s[i] != '<') i++;
        return i != j;
    }

    bool validContent(string s, int& i) {
        int j = i;
        while (j < s.size()) {
            if (!validText(s, j) && !validCData(s, j) && !validTag(s, j)) break;
        }
        i = j;
        return true;
    }

    string parseTagName(string s, int& i) {
        if (s[i] != '<') return "";
        int j = s.find('>', i);
        if (j == string::npos || j - i - 1 < 1 || j - i - 1 > 9) return "";

        string tag = s.substr(i+1, j-i-1);
        for (char c : tag) {
            if (c < 'A' || c > 'Z') return "";
        }
        i = j + 1;
        return tag;
    }

    bool validTag(string s, int& i) {
        int j = i;
        string tag = parseTagName(s, j);
        if (tag.empty()) return false;
        if (!validContent(s, j)) return false;

        int k = j + tag.size() + 2;
        if (k >= s.size() || s.substr(j, k+1-j) != "</" + tag + ">") return false;

        i = k + 1;
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isValid("<DIV>This is the first line <![CDATA[<div>]]></DIV>") << endl;
}
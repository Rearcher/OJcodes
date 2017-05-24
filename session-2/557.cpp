// 557. Reverse Words in a String III
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        int n = s.length(), i = 0, j = 0;
        
        while (j < n) {
            while (j < n && s[j] != ' ') j++;
            string temp = s.substr(i, j - i);
            reverse(temp.begin(), temp.end());
            result.append(temp);
            
            if (j < n) {
                result.push_back(' ');
                j += 1;
                i = j;
            } 
        }

        return result;
    }
};

int main() {
    Solution s;
    cout << s.reverseWords("Let's take LeetCode contest") << endl;
}
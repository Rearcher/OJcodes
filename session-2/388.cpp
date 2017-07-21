// 388. Longest Absolute File Path
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> prefix;
        stack<string> indent;

        int i = 0, result = 0;
        while (i < input.size() && input[i] != '\n') i++;
        if (i >= input.size() && input.find('.') != string::npos) return i;

        prefix.push_back(i);
        indent.push("\n");

        while (i < input.size()) {
            int j = i;
            while (j < input.size() && (input[j] == '\n' || input[j] == '\t')) j++;
            string curIndent = input.substr(i, j - i);

            int k = j;
            while (k < input.size() && input[k] != '\n') k++;
            string curName = input.substr(j, k - j);

            while (!indent.empty() && indent.top().size() >= curIndent.size()) {
                prefix.pop_back();
                indent.pop();
            }

            prefix.push_back(curName.size());
            indent.push(curIndent);

            if (curName.find('.') != string::npos) {
                int curLength = accumulate(prefix.begin(), prefix.end(), 0) + prefix.size() - 1;
                result = max(result, curLength);
            }

            i = k;
        }

        return result;
    }
};

int main() {
    Solution s;
    // string input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    // string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    string input = "a\n\tb.txt\na2\n\tb2.txt";
    cout << s.lengthLongestPath(input) << endl;
    // for (char c : input)
        // cout << c << " ";
    // cout << "\n";
}
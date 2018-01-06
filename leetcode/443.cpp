// 443. String Compression
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, j = 0;
        while (j < chars.size()) {
            int cnt = 0, begin = j;
            while (j < chars.size() && chars[j] == chars[begin]) {
                j++;
                cnt++;
            }

            chars[i++] =  chars[begin];
            if (cnt > 1) {
                string num = to_string(cnt);
                for (int k = 0; k < num.size(); ++k)
                    chars[i++] = num[k];
            }
        }
        return i;         
    }
};

int main() {
    Solution s;
    // vector<char> chars{'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    // vector<char> chars{'a'};
    vector<char> chars{'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    int len = s.compress(chars);
    for (int i = 0; i < len; ++i)
        cout << chars[i] << " ";
    cout << "\n";
    cout << len << endl;
}
// 567. Permutation in String
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;

        vector<int> count(26, 0);
        for (int i = 0; i < s1.size(); ++i) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        if (isPermutation(count)) return true;

        for (int i = s1.size(); i < s2.size(); ++i) {
            count[s2[i-s1.size()] - 'a']++;
            count[s2[i] - 'a']--;
            if (isPermutation(count)) return true;
        }

        return false;
    }

private:
    bool isPermutation(vector<int>& count) {
        for (int i = 0; i < count.size(); ++i)
            if (count[i]) return false;
        return true;
    }
};

int main() {
    Solution s;
    cout << s.checkInclusion("ab", "eidbaoooo") << endl;
}
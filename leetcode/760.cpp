// 760. Find Anagram Mappings
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> result;
        unordered_map<int, int> m;

        for (int i = 0; i < B.size(); ++i)
            m[B[i]] = i;
        for (int i = 0; i < A.size(); ++i)
            result.push_back(m[A[i]]);
        return result;
    }
};

int main() {
    vector<int> A{12, 28, 46, 32, 50};
    vector<int> B{50, 12, 32, 46, 28};
    Solution s;

    vector<int> result = s.anagramMappings(A, B);
    for (int a : result) cout << a << " ";
}
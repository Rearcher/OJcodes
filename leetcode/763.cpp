// 763. Partition Labels
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> m;
        for (int i = 0; i < S.size(); ++i)
            m[S[i]] = i;

        vector<int> result;
        int i = 0;
        while (i < S.size()) {
            int j = m[S[i]], k = i;
            while (k <= j) {
                if (m[S[k]] > j) j = m[S[k]];
                k++;
            }
            result.push_back(j - i + 1);
            i = j + 1;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> res = s.partitionLabels("ababcbacadefegdehijhklij");
    for (int i : res) cout << i << " ";
    cout << "\n";
}
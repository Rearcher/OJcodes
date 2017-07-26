// 646. Maximum Length of Pair Chain
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [&](vector<int> &v1, vector<int>& v2) {
            if (v1[1] == v2[1])
                return v1[0] < v2[0];
            return v1[1] < v2[1];
        });
        
        int count = 1, end = pairs[0][1];
        for (int i = 1; i < pairs.size(); ++i) {
            if (pairs[i][0] > end) {
                end = pairs[i][1];
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution s;
    vector<vector<int>> pairs{{1, 2}, {2, 3}, {3, 4}};
    cout << s.findLongestChain(pairs) << endl;
}
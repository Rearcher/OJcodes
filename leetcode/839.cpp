// 839. Similar String Groups
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        int n = A.size();
        if (n < 2) return n;

        int sz = n;
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);

        for (int i = 0; i < A.size(); ++i)
            for (int j = i + 1; j < A.size(); ++j)
                if (isSimilar(A[i], A[j]))
                    connect(p, i, j, sz);
        return sz;
    }

private:
    bool isSimilar(string a, string b) {
        int cnt = 0;
        for (int i = 0; i < a.size(); ++i)
            if (a[i] != b[i] && ++cnt > 2) 
                return false;
        return true;
    }

    int find(vector<int>& p, int i) {
        while (i != p[i]) {
            p[i] = p[p[i]];
            i = p[i];
        }
        return i;
    }

    void connect(vector<int>& p, int a, int b, int& sz) {
        int i = find(p, a), j = find(p, b);
        if (i != j) {
            p[i] = j;
            sz--;
        }
    }
};

int main() {
    Solution s;
    vector<string> A{"tars","rats","arts","star"};
    cout << s.numSimilarGroups(A) << endl;
}
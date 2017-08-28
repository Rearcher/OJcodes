// 446. Arithmetic Slices II - Subsequence
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int cnt = 0;
        bool valid = true;
        for (int i = 2; i < A.size(); i++) {
            if ((long long)A[i] - (long long)A[i-1] != (long long)A[i-1] - (long long)A[i-2]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            int len = A.size();

            if ((long long)A[1] - (long long)A[0] == 0)
                return pow(2, len) - 1 - len - (len - 1) * len / 2;

            int cnt = (len - 1) * (len - 2) / 2, begin = 5, inc = 2;
            while (begin <= len) {
                int tmp = begin;
                while (tmp <= len) {
                    cnt += (len - tmp + 1);
                    tmp += inc;
                }
                inc += 1;
                begin += 2;
            }

            return cnt;
        }

        vector<int> cur;
        dfs(A, cur, 0, cnt);
        return cnt;
    }

private:
    void dfs(vector<int>& A, vector<int>& cur, int begin, int& cnt) {
        if (cur.size() >= 3) {
            cnt += 1;
        }

        for (int i = begin; i < A.size();) {
            if (cur.size() <= 1) {
                cur.push_back(A[i]);
                dfs(A, cur, i + 1, cnt);
                cur.pop_back();

                i++;
            } else {
                long long inc = (long long)cur[1] - (long long)cur[0], j = i;
                while (j < A.size() && (long long)A[j] - (long long)cur.back() != inc) j++;
                if (j >= A.size()) return;

                cur.push_back(A[j]);
                dfs(A, cur, j + 1, cnt);
                cur.pop_back();

                i = j + 1;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> A{1, 2, 3, 4, 5, 6};
    cout << s.numberOfArithmeticSlices(A) << endl;
}
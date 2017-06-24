// 547. Friend Circles
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<bool> isVisited(M.size(), false);
        int count = 0;

        for (int i = 0; i < M.size(); ++i) {
            if (!isVisited[i]) {
                dfs(M, isVisited, i);
                count += 1;
            }
        }

        return count;
    }

private:
    void dfs(vector<vector<int>>& M, vector<bool>& isVisited, int i) {
        for (int j = 0; j < M.size(); ++j) {
            if (M[i][j] == 1 && !isVisited[j]) {
                isVisited[j] = true;
                dfs(M, isVisited, j);
            }
        }
    }
};

int main() {

}
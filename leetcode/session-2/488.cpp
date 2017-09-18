// 488. Zuma Game
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findMinStep(string board, string hand) {
        unordered_map<char, int> cnt;
        for (char c : hand) cnt[c] += 1;
        return dfs(board, cnt);
    }

private:
    int dfs(string board, unordered_map<char, int>& cnt) {
        board = normalize(board);
        if (board.empty()) return 0;

        int result = INT_MAX, need = 0;
        int i = 0;
        while (i < board.size()) {
            int j = i + 1;
            while (j < board.size() && board[j] == board[i]) j++;

            need = 3 - (j - i);
            need = need < 0 ? 0 : need;
            if (cnt[board[i]] >= need) {
                cnt[board[i]] -= need;
                int tmp = dfs(board.substr(0, i) + board.substr(j), cnt);
                if (tmp != -1) result = min(result, need + tmp);
                cnt[board[i]] += need;
            }
            i = j;
        }

        return result == INT_MAX ? -1 : result;
    }

    string normalize(string s) {
        string result = "";
        int i = 0;

        while (i < s.size()) {
            int j = i + 1;
            for (; j < s.size() && s[j] == s[i]; j++);
            if (j - i >= 3) {
                i = j;
                continue;
            }

            while (i < j) result.push_back(s[i++]);
        }

        return result;
    }
};

int main() {
    Solution s;
    cout << s.findMinStep("RRGGWYYWWGGR", "YRG") << endl;
    // cout << s.findMinStep("WWRRBBWW", "WRBRW") << endl;
}
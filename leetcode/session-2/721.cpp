// 721. Account Merge
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n), sz(n);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            sz[i] = 1;
        }

        for (int i = 0; i < n; ++i) {
            unordered_set<string> s;
            for (int k = 1; k < accounts[i].size(); ++k) s.insert(accounts[i][k]);
            for (int j = i + 1; j < n; ++j) {
                if (i == j) continue;
                for (int k = 1; k < accounts[j].size(); ++k) {
                    if (s.count(accounts[j][k])) {
                        merge(parent, sz, i, j);
                        break;
                    }
                }
            }
        }

        vector<vector<string>> result;
        for (int i = 0; i < n; ++i) {
            set<string> mails;
            for (int j = 0; j < n; ++j) {
                if (find(parent, j) != i) continue;
                for (int k = 1; k < accounts[j].size(); ++k)
                    mails.insert(accounts[j][k]);
            }
            if (mails.empty()) continue;
            
            vector<string> temp{accounts[i][0]};
            temp.insert(temp.end(), mails.begin(), mails.end());
            result.push_back(temp);
        }

        return result;
    }

private:
    int find(vector<int>& parent, int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void merge(vector<int>& parent, vector<int>& sz, int x, int y) {
        int i = find(parent, x), j = find(parent, y);
        if (i == j) return;
        
        if (sz[i] < sz[j]) {
            parent[i] = j;
            sz[j] += sz[i];
        } else {
            parent[j] = i;
            sz[i] += sz[j];
        }
    }
};

int main() {
    Solution s;
    // vector<vector<string>> accounts{{"David","David0@m.co","David1@m.co"},{"David","David3@m.co","David4@m.co"},{"David","David4@m.co","David5@m.co"},{"David","David2@m.co","David3@m.co"},{"David","David1@m.co","David2@m.co"}};
    // vector<vector<string>> accounts{{"John","johnsmith@mail.com","john_newyork@mail.com"},{"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}};
    vector<vector<string>> accounts{
        {"Lily","Lily4@m.co","Lily5@m.co"},
        {"Lily","Lily8@m.co","Lily9@m.co"},
        {"Lily","Lily15@m.co","Lily16@m.co"},
        {"Lily","Lily19@m.co","Lily20@m.co"},
        {"Lily","Lily6@m.co","Lily7@m.co"},
        {"Lily","Lily10@m.co","Lily11@m.co"},
        {"Lily","Lily5@m.co","Lily6@m.co"},
        {"Lily","Lily13@m.co","Lily14@m.co"},
        {"Lily","Lily9@m.co","Lily10@m.co"},
        {"Lily","Lily1@m.co","Lily2@m.co"},
        {"Lily","Lily3@m.co","Lily4@m.co"},
        {"Lily","Lily2@m.co","Lily3@m.co"},
        {"Lily","Lily11@m.co","Lily12@m.co"},
        {"Lily","Lily7@m.co","Lily8@m.co"},
        {"Lily","Lily12@m.co","Lily13@m.co"},
        {"Lily","Lily18@m.co","Lily19@m.co"},
        {"Lily","Lily17@m.co","Lily18@m.co"},
        {"Lily","Lily16@m.co","Lily17@m.co"},
        {"Lily","Lily14@m.co","Lily15@m.co"},
        {"Lily","Lily0@m.co","Lily1@m.co"}};
    auto result = s.accountsMerge(accounts);
    for (auto v : result) {
        for (auto c : v)
            cout << c << " ";
        cout << "\n";
    }
}
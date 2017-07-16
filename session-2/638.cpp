// 638. Shopping Offers
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int specialSum = dfs(price, special, needs, unordered_map<string, int>{});
        int commonSum = 0;
        for (int i = 0; i < needs.size(); ++i) {
            commonSum += price[i] * needs[i];
        }
        return min(specialSum, commonSum);
    }

private:
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, unordered_map<string, int> cache) {
        string key = toString(needs);
        if (cache.count(key)) return cache[key];

        int sum = INT_MAX;
        for (vector<int> sp : special) {
            vector<int> updateNeeds = vector<int>(needs);
            bool quit = false;

            for (int i = 0; i < needs.size(); ++i) {
                if (sp[i] > updateNeeds[i]) {
                    quit = true;
                    break;
                }
                updateNeeds[i] -= sp[i];    
            }

            if (quit) continue;
            sum = min(sum, dfs(price, special, updateNeeds, cache) + sp.back());
        }

        if (sum == INT_MAX) {
            sum = 0;
            for (int i = 0; i < needs.size(); ++i)
                sum += price[i] * needs[i];
        }

        cache[key] = sum;
        return sum;
    }

    string toString(vector<int>& needs) {
        stringstream ss;
        for (int i = 0; i < needs.size(); ++i) {
            if (i != 0) ss << ",";
            ss << to_string(needs[i]);
        }
        return ss.str();
    }
};

int main() {
    
}
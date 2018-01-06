// Distinct Subsequences
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) {
		int dp[t.size() + 1][s.size() + 1];

		for (int i = 0; i <= s.size(); ++i)
			dp[0][i] = 1;
		for (int i = 1; i <= t.size(); ++i)
			dp[i][0] = 0;

		for (int i = 0; i < t.size(); ++i) {
			for (int j = 0; j < s.size(); ++j) {
				if (t[i] == s[j]) {
					dp[i+1][j+1] = dp[i][j] + dp[i+1][j];
				}
			}
		}

		return dp[t.size()][s.size()];
	}
};

class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &wordDict) {
		if(wordDict.size() == 0) return false;

		vector<bool> dp(s.size()+1, false);
		dp[0] = true;

		for(int i=1; i<=s.size(); i++) {
			for(int j=i-1; j>=0; j--) {
				if(dp[j]) {
					string str = s.substr(j, i-j);
					if(wordDict.find(str) != wordDict.end()) {
						dp[i] = true;
						break;
					}
				}
			}
		}
		return dp[s.size()];
	}
};

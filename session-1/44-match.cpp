class Solution {
public:
	bool isMatch(string s, string p) {
		int m=s.size(), n=p.size();
		vector<vector<bool>> dp(m+1, vector<bool>(n+1,0));

		dp[0][0] = true;
		for(int i=1; i<=m; i++)
			dp[i][0] = false;
		for(int j=1; j<=n; j++)
			dp[0][j] = (p[j-1]=='*' && dp[0][j-1]);

		for(int i=1; i<=m; i++) {
			for(int j=1; j<=n; j++) {
				if(p[j-1]!='*')
					dp[i][j] = dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='?')
				else
					dp[i][j] = dp[i][j-1] || dp[i-1][j];
			}
		}
		return dp[m][n];
	}
}//TLE

class Solution {
public:
	bool isMatch(string s, string p) {
		int m=s.size(), n=p.size();
		int i=0, j=0;
		int pos1=-1, pos2=-1;

		while(i<m) {
			if(s[i]==p[j] || p[j]=='?') {
				i++;j++;
				continue;
			}
			if(p[j]=='*') {
				pos1 = j; pos2 = i; j++;
				continue;
			}
			if(pos1!=-1) {
				i = ++pos2; j = pos1+1; pos2++;
				continue;
			}
			return false;
		}
	
		while(p[j]=='*') j++;
		return j==n;
	}
}

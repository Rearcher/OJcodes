class Solution {
public:
	bool isScramble(string s1, string s2) {
		if(s1.size()!=s2.size()) return false;
		int n=s1.size();
		bool dp[n+1][n+1][n+1];  
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				dp[1][i][j] = (s1[i]==s2[j]);
		for(int k=2; k<=n; k++){
			for(int i=0; i<n-k+1; i++){
				for(int j=0; j<n-k+1; j++) {
					for(int l=1; l<k; l++) {
						dp[k][i][j] = (dp[l][i][j]&&dp[k-l][i+k][j+k])||(dp[l][i][j+k-l]&&dp[k-l][i+k][j]);
					}
				}
			}
		}
		return dp[n][0][0];
	}

};

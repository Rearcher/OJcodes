class Solution {
public:
	int numDecodings(string s) {
		int n=s.size();
		if(!n) return 0;
		vector<int> ans(n+1,0);
		ans[0] = 1;
		ans[1] = (s[0]=='0'?0:1);
		for(int i=2; i<=n; i++) {
			if(s[i-1]=='0') ans[i] = 0;
			else ans[i] = ans[i-1];
			if(s[i-2]=='1' || (s[i-2]=='2'&&s[i-1]<='6'))
				ans[i] += ans[i-2];
		}
		return ans[n];
	}
};

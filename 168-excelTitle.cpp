class Solution {
public:
	string convertToTitle(int n) {
		string ans;
		if(n<=26) {
			ans += ('A'+n-1);
			return ans;
		}
		while(n) {
			int t=n%26;
			if(t) {
				ans += ('A'+t-1);
				n /= 26;
			}
			else {
				ans += 'Z';
				n = n/26-1;
			}
			
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

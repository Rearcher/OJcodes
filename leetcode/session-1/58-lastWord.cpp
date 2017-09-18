class Solution {
public:
	int lengthOfLastWord(string s) {
		int n=s.size(), i;
		for(i=n-1; i>=0 && s[i]==' '; i--);
		if(i<0) return 0;
		else {
			int ans=0;
			while(i>=0 && s[i]!=' ') {
				i--;
				ans++;
			}
			return ans;
		}
	}
};

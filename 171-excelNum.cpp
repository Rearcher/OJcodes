class Solution {
public:
	int titleToNumber(string s) {
		int col=0;
		for(int i=0; i<s.size(); i++) {
			int n=s[i]-'A'+1;
			col = col*26+n;
		}
		return col;
	}
};

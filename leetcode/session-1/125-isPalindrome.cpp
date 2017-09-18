class Solution {
public:
	bool isPalindrome(string s) {
		if(s.empty()) return true;
		string t;
		for(int i=0; i<s.size(); i++) {
			if((s[i]>='0'&&s[i]<='9')||(s[i]>='A'&&s[i]<='Z'))
				t.push_back(s[i]);
			else if(s[i]>='a'&&s[i]<='z')
				t.push_back(s[i]-32);
		}
		int len=t.size();
		int i=0, j=len-1;
		while(i<j) {
			if(t[i]!=t[j])
				return false;
			i++;
			j--;
		}
		return true;
	}
};

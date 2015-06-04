class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int ans=0;
		int i=0, j=0;
		bool exist[256] = {false};
		while(j < s.length()) {
			if(exist[s[j]]) {
				ans = max(ans, j-i);
				while(s[i]!=s[j]) {
					exist[s[i]] = false;
					i++;
				}
				i++;
				j++;
			}
			else {
				exist[s[j]] = true;
				j++;
			}
		}
		ans = max(ans, j-i);
		return ans;
	}
}


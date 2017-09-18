class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int ans=0;
		int i=0, j=0;
		bool exist[256] = {false};
		//Why the length is 256? Because char is between 0-255
		while(j < s.length()) {
			if(exist[s[j]]) {
				ans = max(ans, j-i);
				while(s[i]!=s[j]) {
					exist[s[i]] = false;
					i++;
				}
				i++;//当出现重复字符时，必须重新定位到前面重复字符的后一个位置
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


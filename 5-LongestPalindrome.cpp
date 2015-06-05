/*========================Solution 1, use dp========================*/
//224ms, O(N^2)
class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.length();
		int maxlen = 1;
		int begin = 0;
		bool table[1000][1000] = {false};

		for(int i = 0; i < n; i++)
			table[i][i] = true;

		for(int i = 0; i < n-1; i++) {
			if(s[i] == s[i+1]) {
				table[i][i+1] = true;
				begin = i;
				maxlen = 2;
			}
		}

		for(int len = 3; len <= n; len++) {
			for(int i = 0; i < n-len+1; i++) {
				int j = i+len-1;
				if(s[i]==s[j] && table[i+1][j-1]) {
					begin = i;
					maxlen = len;
					table[i][j] = true;
				}
			}
		}
		return s.substr(begin, maxlen);
	}
}

/*======================Solution2, expand from center===============*/
//80ms, O(N^2)
class Solution {
public:
	string expand(string s, int index1, int index2) {
		int l = index1, r = index2;
		int n = s.length();
		while(l>=0 && r<=n-1 && s[l]==s[r]) {
			l--;
			r++;
		}
		return s.substr(l+1, r-l-1);
	}
	
	string longestPalindrome(string s) {
		int n = s.length();
		if(!n) return "";
		string ans = s.substr(0,1);
		for(int i = 0; i < n-1; i++) {
			string p1 = expand(s,i,i);
			if(p1.length() > ans.length())
				ans = p1;

			string p2 = expand(s,i,i+1);
			if(p2.length() > ans.length())
				ans = p2;
		}
		return ans;
	}
}


/*=============================Solution3============================*/
//
class Solution {
public:
	string expand(string s, int index1, int index2) {
		
	}
}

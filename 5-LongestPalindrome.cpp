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
//124ms, O(N)
//references:http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
class Solution {
public:
	//for example, change "abcde" to "^#a#b#c#d#e#$"
	string preProcess(string s) {
		int n = s.length();
		if(n == 0) return "^$";
		string ret = "^";
		for(int i = 0; i < n; i++) 
			ret += '#'+s.substr(i,1);
		ret += "#$";
		return ret;
	}
	
	string longestPalindrome(string s) {
		string T = preProcess(s);	
		int n = T.length();
		int *p = new int[n];
		int c = 0, r = 0;
		for(int i = 1; i < n-1; i++) {
			int i_mirror = 2*c-i; //(i+i_mirror)/2=c
			p[i] = (r > i) ? min(r-i, p[i_mirror]) : 0;

			while(T[i+1+p[i]] == T[i-1-p[i]])
				p[i]++;

			if(i + p[i] > r) {
				c = i;
				r = 1 + p[i];
			}
		}

		int maxlen = 0;
		int center = 0;
		for(int i = 1; i < n-1; i++) {
			if(p[i] > maxlen) {
				maxlen = p[i];
				center = i;
			}
		}
		delete[] p;

		return s.substr((center-1-maxlen)/2, maxlen);
	}
}

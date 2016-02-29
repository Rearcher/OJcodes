class Solution {
public:
	bool isPalindrome(string s) {
		if(s.empty() || s.size()==1) return true;
		for(int i=0, j=s.size()-1; i<j; i++,j--) {
			if(s[i] != s[j]) return false;
		}
		return true;
	}

	void backtracking(vector<vector<string>> &ans, vector<string> cur, string s, int index) {
		if(index >= s.size()) {
			ans.push_back(cur);
			return;
		}
		for(int i=1; i+index<=s.size(); i++) {
			string t = s.substr(index, i);
			if(!isPalindrome(t)) continue;
			cur.push_back(t);
			backtracking(ans, cur, s, index+i);
			cur.pop_back();
		}

	}

	vector<vector<string>> partition(string s) {
		vector<vector<string>> ans;		
		backtracking(ans, vector<string>(), s, 0);
		return ans;
	}
};

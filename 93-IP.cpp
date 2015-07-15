class Solution {
public:
	void backtracking(vector<string>& ans, string t, string s, int pos, int depth) {
		if(depth == 4) {
			if(pos < s.size()) return;
			else ans.push_back(t);
		}
		else if(!t.empty()) t.push_back('.');
		
		for(int i=3; i>=1; i--) {
			if(pos+i>s.size()) continue;
			string str = s.substr(pos,i);
			if(i>=2 && str[0]=='0') continue;
			if(i==3 && str > "255") continue;
			for(int k=0; k<i; k++) t.push_back(s[pos+k]);
			backtracking(ans, t, s, pos+i, depth+1);
			for(int k=0; k<i; k++) t.pop_back();
		}
		return;
	}

	vector<string> restoreIpAddresses(string s) {
		vector<string> ans;
		string t;
		backtracking(ans, t, s, 0, 0);
		return ans;
	}
};

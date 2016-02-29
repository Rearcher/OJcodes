class Solution {
public:
	void backtracking(vector<string>& res, string t, int l, int r, int n) {
		if(l==n && r==n) {
			res.push_back(t);
			return;
		}
		if(l<r) return;
		if(l < n) {
			t.push_back('(');
			backtracking(res, t, l+1, r, n);
			t.pop_back();
		}
		if(r < n) {
			t.push_back(')');
			backtracking(res, t, l, r+1, n);
			t.pop_back();
		}
	}
	
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		string t;
		backtracking(res, t, 0, 0, n);
		return res;
	}
}

class Solution {
public:
	void backtracking(vector<vector<int>> &ans, vector<int> cur, int n, int depth, int start, int k) {
		if(n < 0) return;
		if(depth == k) {
			if(n==0) ans.push_back(cur);
			return;
		}

		for(int i=start+1; i<=9; i++) {
			cur.push_back(i);
			backtracking(ans, cur, n-i, depth+1, i, k);
			cur.pop_back();
		}
		return;
	}

	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> ans;
		if(n<3) return ans;
		backtracking(ans, vector<int>(), n, 0, 0, k);
		return ans;
	}
};

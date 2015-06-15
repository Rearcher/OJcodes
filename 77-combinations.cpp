class Solution {
public:
	void backtracking(vector<vector<int>>& ans, vector<int>t, int begin, int depth, int k, int n) {
		if(depth==k) {
			ans.push_back(t);
			return;
		}
		for(int i=begin; i<=n; i++) {
			t.push_back(i);
			backtracking(ans,t,i+1,depth+1,k,n);
			t.pop_back();
		}
		return;
	}
	
	vector<vector<int>> combine(int n, int k) {
		int m=n-k;
		vector<vector<int>> ans;
		vector<int> t;
		if(m<0) return ans;
		else if(m==0) {
			for(int i=1; i<=n; i++) t.push_back(i);
			ans.push_back(t);
			return ans;
		}
		backtracking(ans,t,1,0,k,n);
		return ans;
	}
};

//SolutionII, the idea is C(n,k) = C(n-1,k-1)U(n) + C(n-1,k);
vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> ans;
	if(n<1 || k<1 || k>n) return ans;

	ans = combine(n-1,k-1);

	if(ans.empty()) ans.push_back(vector<int>{n});
	else {
		for(vector<vector<int>>::iterator it=ans.begin(); it!=ans.end(); it++)
			it->push_back(n);
	}
	vector<vector<int>> ans2 = combine(n-1,k);
	ans.insert(ans.end(), ans2.begin(), ans2.end());
	return ans;
}

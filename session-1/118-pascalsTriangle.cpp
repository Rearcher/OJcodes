class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ans;
		if(numRows==0) return ans;
		else if(numRows==1) {
			ans.push_back(vector<int>{1});
			return ans;
		}
		else if(numRows==2) {
			ans.push_back(vector<int>{1});
			ans.push_back(vector<int>{1,1});
			return ans;
		}

		ans.push_back(vector<int>{1});
		ans.push_back(vector<int>{1,1});
		for(int i=3; i<=numRows; i++) {
			vector<int> t;
			t.push_back(1);
			for(int j=0; j<ans[i-1].size()-1; j++)
				t.push_back(ans[i-1][j]+ans[i-1][j+1]);
			t.push_back(1);
		}
		return ans;
	}
};

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m=grid.size();
		int n=grid[0].size();
		vector<int> res(n,0);

		res[0] = grid[0][0];
		for(int j=1; j<n; j++) res[j]=res[j-1]+grid[0][j];
		for(int i=1; i<m; i++)
			for(int j=0; j<n; j++) {
				if(j==0) res[j] += grid[i][j];
				else res[j] = min(res[j],res[j-1])+grid[i][j];
			}
		return res[n-1];
	}
};

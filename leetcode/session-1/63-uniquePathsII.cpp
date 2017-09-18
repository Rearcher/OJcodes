class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m=obstacleGrid.size();
		int n=obstacleGrid[0].size();

		vector<int> res(n,0);
		res[0] = 1;
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++) {
				if(obstacleGrid[i][j]==1) res[j]=0;
				else if(j>0) res[j] += res[j-1];
			}

		return res[n-1];
	}
}

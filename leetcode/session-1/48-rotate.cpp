class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n=matrix.size();
		vector<vector<int>> copy = matrix;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				matrix[j][n-i-1]=copy[i][j];
		return;
	}
};

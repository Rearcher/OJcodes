class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		if(matrix.empty()) return;
		int m=matrix.size();
		int n=matrix[0].size();
		unordered_map<int,int> row, col;
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				if(matrix[i][j]==0) {
					if(row.find(i)==row.end())
						row[i] = i;
					if(col.find(j)==col.end())
						col[j] = j;
				}
			}
		}
		unordered_map<int,int>::iterator it;
		for(it=row.begin(); it!=row.end(); it++)
			for(int i=0; i<n; i++)
				matrix[it->first][i] = 0;
		for(it=col.begin(); it!=col.end(); it++)
			for(int i=0; i<m; i++)
				matrix[i][it->first] = 0;
		return;
	}
};

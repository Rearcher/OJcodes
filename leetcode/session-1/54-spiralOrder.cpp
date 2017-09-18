class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> >& matrix) {
		vector<int> ans;
		if(matrix.empty()) return ans;
		else if(matrix.size()==1) return matrix[0];
		
		int row=matrix.size(), col=matrix[0].size();
		vector<vector<int> > visited;
		vector<int> line(col,0);
		for(int i=0; i<row; i++) visited.push_back(line);

		int dir=1, m=0, n=0, cnt=row*col;
		while(cnt--) {
			ans.push_back(matrix[m][n]);
			visited[m][n] = 1;
			if(dir==1) { //left
				if(n+1<col && !visited[m][n+1]) n++;
				else {dir=2; m++;}
			}
			else if(dir==2) { //down
				if(m+1<row && !visited[m+1][n]) m++;
				else {dir=3; n--;}
			}
			else if(dir==3) { //right
				if(n-1>=0 && !visited[m][n-1]) n--;
				else {dir=4; m--;}
			}
			else if(dir==4) { //up
				if(m-1>=0 && !visited[m-1][n]) m--;
				else {dir=1; n++;}
			}
		}
		return ans;
	}
};

class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		vector<vector<int> >ans;
		vector<vector<int> >visited;
		vector<int>line(n,0);
		for(int i=0; i<n; i++) {
			ans.push_back(line);
			visited.push_back(line);
		}

		int i=0, j=0, dir=1;
		for(int num=1; num<=n*n; num++) {
			ans[i][j] = num;
			visited[i][j] = 1;
			if(dir==1) { //left
				if(j+1<n && !visited[i][j+1]) j++;
				else {dir=2; i++;}
			}
			else if(dir==2) { //down
				if(i+1<n && !visited[i+1][j]) i++;
				else {dir=3; j--;}
			}
			else if(dir==3) { //right
				if(j-1>=0 && !visited[i][j-1]) j--;
				else {dir=4; i--;}
			}
			else if(dir==4) { //up
				if(i-1>=0 && !visited[i-1][j]) i--;
				else {dir=1; j++;}
			}
		}
		return ans;
	}
};

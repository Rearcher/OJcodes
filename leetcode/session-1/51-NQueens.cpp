class Solution {
public:
	void backtracking(vector<vector<string> >& res, vector<string>& t, int depth, int n) {
		if(depth==n) res.push_back(t);
		for(int i=0; i<n; i++) {
			bool flag=true;
				for(int j=0; j<depth; j++) {		//=============judge vertical Queen
				if(t[j][i]=='Q') {flag=false; break;}
			}

			int row=depth-1, col=i-1;				//=============judge upper left Queen
			while(row>=0 && col>=0 && flag) {
				if(t[row][col]=='Q') flag=false;
				row--; col--;
			}
			row=depth-1, col=i+1;					//=============judge upper right Queen
			while(row>=0 && col<n && flag) {
				if(t[row][col]=='Q') flag=false;
				row--; col++;
			}
		
			if(flag) {
				string temp;
				for(int j=0; j<i; j++) temp.push_back('.');
				temp.push_back('Q');
				for(int j=i+1; j<n; j++) temp.push_back('.');
				t.push_back(temp);
				backtracking(res, t, depth+1, n);
				t.pop_back();
			}
		}
		return;
	}

	vector<vector<string> > solveNQueens(int n) {
		vector<vector<string> > ans;
		vector<string> t;
		backtracking(ans, t, 0, n);
		return ans;
	}
};

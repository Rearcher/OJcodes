class Solution {
public:
	void backtracking(vector<string>& t, int depth, int n, int& cnt) {
		if(depth==n) cnt++;;
		for(int i=0; i<n; i++) {
			bool flag=true;
			for(int j=0; j<depth; j++) {
				if(t[j][i]=='Q') {flag=false; break;}
			}

			int row=depth-1, col=i-1;
			while(row>=0 && col>=0 && flag) {
				if(t[row][col]=='Q') flag=false;
				row--; col--;
			}
			row=depth-1, col=i+1;
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
				backtracking(t, depth+1, n, cnt);
				t.pop_back();
			}
		}
		return;
	}

	int totalNQueens(int n) {
		int ans;
		vector<string> t;
		backtracking(t, 0, n, ans);
		return ans;
	}
};

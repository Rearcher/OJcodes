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

//=============Another solution, use vector flag to judge the position
//total N columns, use index 0 to N-1 to mark
//total 2N-1 diagonals(45 degree), use index N to 3*N-2 to mark
//total 2N-1 diagonals(135 degree), use index 3*N-1 to 5*N-3 to mark

class Solution {
public:
	void backtracking(vector<string>& t, vector<int>& flag, int depth, int n, int& cnt) {
		if(depth==n) cnt++;;
		for(int i=0; i<n; i++) {
			if(flag[i] && flag[i+depth+n] && flag[i-depth+4*n-2])
			{
				flag[i] = flag[i+depth+n] = flag[i-depth+4*n-2] = 0;
				string temp;
				for(int j=0; j<i; j++) temp.push_back('.');
				temp.push_back('Q');
				for(int j=i+1; j<n; j++) temp.push_back('.');
				t.push_back(temp);
				backtracking(t, flag, depth+1, n, cnt);
				t.pop_back();
				flag[i] = flag[i+depth+n] = flag[i-depth+4*n-2] = 1;
			}
		}
		return;
	}

	int totalNQueens(int n) {
		int ans=0;
		vector<string> t;
		vector<int> flag(5*n-2, 1);
		backtracking(t, flag, 0, n, ans);
		return ans;
	}
};

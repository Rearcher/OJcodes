class Solution {
public:
	int dir[4][2]={{0,-1}, {0,1}, {-1,0}, {1,0}};
	
	void backtracking(int i, int j, vector<vector<char> >& board, vector<vector<int> >& visited, int depth, bool& ans, string& word) {
		if(depth==word.size()) {
			ans = true;
			return;
		}
		int row, col;
		for(int k=0; k<4; k++) {
			row = i+dir[k][0];
			col = j+dir[k][1];
			if(row>=0 && row<board.size() && col>=0 && col<board[0].size()) {
				if(board[row][col]==word[depth] && !visited[row][col]) {
					visited[row][col] = 1;
					backtracking(row,col,board,visited,depth+1,ans,word);
					if(ans) return;			//if not, TLE
					visited[row][col] = 0;
				}
			}
		}
		return;
	}

	bool exist(vector<vector<char> >& board, string word) {
		if(board.empty() || word.empty()) return false;
		int m=board.size(), n=board[0].size();
		vector<vector<int> > visited(m, vector<int>(n,0));

		bool ans=false;
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++) {
				if(board[i][j]==word[0]) {
					visited[i][j] = 1;
					backtracking(i,j,board,visited,1,ans,word);
					visited[i][j] = 0;
					if(ans) return true;
				}
			}
		return ans;
	}
};

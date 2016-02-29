class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		unordered_map<char, int>hmap;
		for(int i=0; i<9; i++) {
			hmap.clear();
			for(int j=0; j<9; j++) {
				if(hmap.find(board[i][j])!=hmap.end()) return false;
				else if(board[i][j]!='.') hmap[board[i][j]]=j;
			}
		}
		
		for(int j=0; j<9; j++) {
			hmap.clear();
			for(int i=0; i<9; i++) {
				if(hmap.find(board[i][j]!=hmap.end())) return false;
				else if(board[i][j]!='.') hmap[board[i][j]]=i;
			}
		}
		int p1=0, p2=0;
		for(p1=0; p1<=6; p1+=3) 
			for(p2=0; p2<=6; p2+=3) {
				hmap.clear();
				for(int i=p1; i<p1+3; i++) {
					for(int j=p2; j<p2+3; j++) {
						if(hmap.find(board[i][j])!=hmap.end()) return false;
						else if(board[i][j]!='.') hmap[board[i][j]]=i;
					}
				}
			}
		return true;
	}
};

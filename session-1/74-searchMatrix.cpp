class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if(matrix.empty()) return false;
		int m=matrix.size(), n=matrix[0].size();

		int lo=0, hi=m-1, row;
		while(lo<hi) {
			int mid=(lo+hi)/2;
			if(matrix[mid][0]==target) return true;
			else if(matrix[mid][0]>target) hi=mid-1;
			else lo=mid+1;
		}
		if(matrix[lo][0]==target) return true;
		else if(matrix[lo][0]<target) row = lo;
		else {
			if(lo==0) return false;
			else row = lo-1;
		}
		if(matrix[row][n-1] < target) return false;
		lo = 0;
		hi = n-1;
		while(lo<hi) {
			int mid=(lo+hi)/2;
			if(matrix[row][mid]==target) return true;
			else if(matrix[row][mid]>target) hi=mid-1;
			else lo=mid+1;
		}
		if(matrix[row][lo]==target) return true;
		return false;
	}
};

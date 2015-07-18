class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> ans(rowIndex+1,0);
		ans[0] = 1;
		for(int i=1; i<rowIndex+1; i++)
			for(int j=i; j>=1; j--)
				ans[j] += ans[j-1];
		return ans;
	}
};

/* some math
 * C(k,p) = k! / (p!*(k-p)!) = C(k,k-p);
 * if p<k-p
 * C(k,p) = C(k,p-1)*(k-p+1)/p;
 */


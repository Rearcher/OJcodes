class Solution {
public:
	int countPrimes(int n) {
		if(n<=2) return 0;
		bool flag[n]={false};
		for(int i=2; i*i<n; i++) {
			if(!flag[i]) {
				for(int j=i; i*j<n; j++) {
					flag[i*j] = true;
				}
			}
		}
		int cnt=0;
		for(int i=2; i<n; i++) {
			if(!flag[i]) cnt++;
		}
		return cnt;
	}	
};

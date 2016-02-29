class Solution {
public:
	double myPow(double x, int n) {
		if(n==0) return 1;
		if(x==0) {
			if(n==0) return 1;
			else return 0;
		}
		long long pow;
		if(n > 0) pow = n;
		else if(n==INT_MIN) pow=INT_MAX+1;
		else pow = -n;

		int cnt=0, inc=1;
		double mul=x,ans=1.0;
		while(cnt<pow) {
			if(cnt+inc > pow) {
				pow -= cnt;
				cnt = 0;
				inc = 1;
				mul = x;
				continue;
			}
			ans *= mul;
			cnt += inc;
			mul *= mul;
			inc += inc;
		}
		if(n<0) return 1.0/ans;
		else return ans;
	}
};

class Solution {
public:
	int mySqrt(int x) {
		if(x<=1) return x;
		unsigned long long lo=1, hi=x/2;
		while(lo<hi) {
			unsigned long long mid=(lo+hi)/2;
			unsigned long long t = mid*mid;
			if(t==x) return mid;
			else if(t>x) hi=mid-1;
			else lo=mid+1;
		}
		if(lo*lo > x) return lo-1;
		return lo;
	}
};

//Math solution, Newton's method
int sqrt(int x) {
	if(x==0) return 0;
	double p, q=1;
	do {
		p = q;
		q = x/(2*p)+p/2.0;
	}while(abs(p-q)>0.00001);
	return int(q);
}

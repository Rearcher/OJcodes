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

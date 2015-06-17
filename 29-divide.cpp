class Solution {
public:
	int divide(int dividend, int divisor) {
		int MAX_INT=0x7fffffff;
		int MIN_INT=1<<31;
		long long a,b;		
		if(dividend == MIN_INT) a = 0x80000000;
		else a = abs(dividend);		//abs cannot convert MIN_INT to positive
		
		if(divisor == MIN_INT)  b = 0x80000000;
		else  b = abs(divisor);
		
		if(divisor==0) return MAX_INT;
		if(dividend==0 || a<b) return 0;

		bool flag1=true, flag2=true;
		if(dividend<0) flag1 = false;
		if(divisor<0) flag2 = false;

		long long sum=0;
		long long count=0, ans=0;

		while(a>=b) {
			count = 1;
			sum = b;
			while(sum+sum<=a) {
				sum += sum;
				count += count;
			}
			a -= sum;
			ans += count;
		}
		if((!flag1&&flag2) || (!flag2&&flag1)) return -ans;
		if(ans==0x80000000) return MAX_INT;  //ans can be -MIN_INT
		return ans;	
	}
};


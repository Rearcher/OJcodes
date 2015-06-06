class Solution{
	int myAtoi(string str) {
		if(str.length()==0) return 0; //if the str is empty
	
		long long min = (1<<31);
		long long max = min & (0x80000000);
		long long ans=0;
		bool flag=true;
		int i;
		for(i=0; i<str.length() && str[i]==' '; i++);
		if(str[i]!='-' && str[i]!='+' && (str[i]<'0'||str[i]>'9'))
			return 0;

		if(str[i]=='-') {flag=false; i++;}
		else if(str[i]=='+') i++;

		for(; i<str.length(); i++) {
			if(str[i]<'0' || str[i]>'9') break;
			int digit=str[i]-'0';
			ans = ans*10+digit;
			if(ans >= max) break; //if ans has been overflow, no need to calculate any more.
		}
	
		if(flag && ans >= max) { //positive overflow
			ans = max-1;
			return ans;
		}
	
		if(!flag && ans >= max) { //negative overflow
			return min;
		}
	
		if(!flag) ans = -ans;	//negative integer
			return ans;
		}
}

class Solution {
public:
	int reverse(int x) {
    	bool flag = false;
    	long long max = (1<<31)&(0x80000000); //the max of 32-bit int
    	long long temp = x;
    	if(x > 0) flag = true;
    	else if(x == 0) return 0;
    	else temp = -temp;;
    
    	if(temp >= max) return 0; //in case of x=-2147483648

    	long long ans = 0;
    	while(temp/10) {
        	int t = temp%10;
        	ans = (ans+t)*10;	//the ans may overflow
        	if(ans >= max) return 0;
        	temp /= 10; 
    	}
    	ans += temp;

       	if(flag) return ans;
       	else return -ans;
}   

}

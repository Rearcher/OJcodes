class Solutin {
public:
	bool isPalindrome(int x) {
    	if(x==0) return true; 
    	if(x < 0) return false; //negative integer has '-',so return false

    	int div=1000000000; //10^9
    	int len=10;
    	while(x/div==0) {
        	len--;
        	div /= 10; 
    	}                       //find out the length of the integer

    	int div2=10;
    	len /= 2;
   	 	while(len--) {    
        	int a = x/div;      //for example, 12321, a=1(left), b=1(right), etc..
        	int b = x%div2;
        	if(a!=b) return false;
        	x = x/div2-div/10*a;    //update x, x should be 232
        	div /= 100;
    	}   
    	return true;
	}
};

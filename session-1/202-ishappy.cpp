class Solution {
public:
	bool isHappy(int n) {
		map<int,int> hmap;
		while(true) {
			int sum=0;
			while(n) {
				sum += (n%10)*(n%10);
				n /=10;
			}
			if(sum==1) return true;
			else if(hmap.find(sum)!=hmap.end()) return false;
			else hmap[sum] = 1;
			n = sum;
		}
	}
};

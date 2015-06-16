class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int n=nums.length();
		if(n<=2) return n;

		for(vector<int>::iterator it=nums.begin(); it!=nums.end()) {
			int cnt=1;
			while(it+1!=nums.end() && (*it)==*(it+1)) {
				cnt++; it++;
				if(cnt>=3) {
					it=nums.erase(it);
					it--;
				}
			}
			it++;
		}
		return nums.size();
	}
};

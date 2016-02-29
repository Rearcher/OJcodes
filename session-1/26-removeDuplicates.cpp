#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if(nums.size() <= 1) return nums.size();
		
		vector<int>::iterator it1,it2;
		for(it1=nums.begin(),it2=nums.begin()+1; it2 != nums.end();) {
			if(*it2 == *it1) it2=nums.erase(it2);
			else {it1++;it2++;}
		}
		
		return nums.size();
	}
};

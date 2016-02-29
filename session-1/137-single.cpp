class Solution {
public:
	int singleNumber(vector<int>& nums) {
		if(nums.size()==1) return nums[0];
		sort(nums.begin(), nums.end());
		if(nums[0] != nums[1]) return nums[0];
		for(int i=1; i<nums.size()-1; i++) {
			if(nums[i]!=nums[i-1] && nums[i]!=nums[i+1])
				return nums[i];
		}
		return nums[nums.size()-1];
	}
};

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		vector<int> count(32,0);
		int result=0;
		for(int i=0; i<32; i++) {
			for(int j=0; j<nums.size(); j++) {
				if((nums[j]>>i)&1) count[i]++;
			}
			result |= ((count[i]%3)<<i);
		}
		return result;
	}
};

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ones=0, twos=0, threes=0;
		//ones用来记录在哪些位上1出现了一次
		//twos用来记录在哪些位上1出现了两次
		for(int i=0; i<nums.size(); i++) {
			twos |= ones & nums[i];  //如果ones某位是1,nums[i]这位也是1,那么这位上的1就出现了两次，所以更新twos
			ones ^= nums[i];  //更新ones
			
			threes = ones & twos;  //如果ones和twos两位都是1,表明出现三次，ones和twos相应位要清零
			ones &= ~threes;
			twos &= ~threes;
		}
		return ones;
	}
};
//就某一位来说，如果1出现0次的时候，twos对应的那一位是0,ones对应的那一位也是0
//如果1出现1次，twos对应的那一位是0,ones对应的那一位变成1
//如果1出现2次，twos对应的那一位变成1,ones对应的那一位变成0
//如果1出现3次，twos对应的那一位还是1,ones对应的那一位变成1,此时twos和ones相应的那位都要清零

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int len = nums.size();
		if(len == 1) return nums[0];

		vector<int> left, right;

		for(int i=1; i<len; i++) {
			if(nums[i] > nums[0])
				right.push_back(nums[i]);
			else
				left.push_back(nums[i]);
		}

		int r_len = right.size();
		if(r_len >= k)
			return findKthLargest(right, k);
		else if(r_len == k-1)
			return nums[0];
		else
			return findKthLargest(left, k-r_len-1);
	}
};

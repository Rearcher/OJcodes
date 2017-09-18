class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if(!n) return;
		vector<int>;
		for(int i=0; i<m; i++) t.push_back(nums1[i]);
		nums1.clear();
		int i=0, j=0;
		while(i<m && j<n) {
			if(t[i] < nums2[j]) {
				nums1.push_back(t[i]);
				i++;
			}
			else {
				nums1.push_back(nums2[j]);
				j++;
			}
		}
		while(i<m) {
			nums1.push_back(t[i]);
			i++;
		}
		while(j<n) {
			nums1.push_back(nums2[j]);
			j++;
		}
		return;
	}
};

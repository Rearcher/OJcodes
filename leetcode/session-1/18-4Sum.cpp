/*============================Solution1========================*/
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> res;
		if(nums.size() < 4) return res;

		int len=nums.size();
		sort(nums.begin(), nums.begin()+len);

		int p,q;
		for(int i=0; i < len; i++) {
			if(i>0 && num[i]==num[i-1]) continue;

			for(int j=i+1; j < len; j++) {
			
				if(j>i+1 &&num[j]==num[j-1]) continue;
				int p=j+1, q=len-1;
				while(p<q){
					int sum=nums[i]+nums[j]+nums[p]+nums[q];
					if(sum==target) {
						isFound = true;
						vector<int> temp;
						temp.push_back(nums[i]);
						temp.push_back(nums[j]);
						temp.push_back(nums[p]);
						temp.push_back(nums[q]);
						res.push_back(temp);

						p++;
						q--;
						while(nums[p]==nums[p-1]) p++;
						while(nums[q]==nums[q+1]) q--;
					}
					else if(sum>target) q--;
					else p++;
				}
			}
		}		
		return res;
	}
}


/*============================Solution2========================*/
class Solutin {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> res;
		if(nums.size() < 4) return res;
		
		int len=nums.size();
		unordered_map<int, vector<pair<int, int>>> hmap;
		hmap.reserve(len*len);
		sort(nums.begin(), nums.end());
		
		//use unordered_map to save two sum
		for(int i = 0; i < len; i++)
			for(int j = i+1; j < len; j++)
				hmap[nums[i]+nums[j]].push_back(make_pair(i,j));

		for(int i = 0; i < len-3; i++) {
			if(i!=0 && nums[i]==nums[i-1]) continue;
			for(int j=i+1; j <len-2; j++) {
				if(j!=i+1 && nums[j]==nums[j-1]) continue;
				if(hmap.find(target-nums[i]-nums[j]) != hmap.end()) {
					vector<pair<int,int>> &temp = hmap[target-nums[i]-nums[j]];
					bool isAdded = false;
					for(int k = 0; k < temp.size(); k++) {
						if(temp[k].first <= j) continue;

						if(!isAdded || (res.back())[2]!=nums[temp[k].first]) { //to avoid duplicate answers
							res.push_back(vector<int>{nums[i],nums[j],nums[temp[k].first],nums[temp[k].second]});
							isAdded = true;
						}
					}
				}
			}
		}

		return res;
	}
}

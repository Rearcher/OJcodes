class Solution {
public:
	void backtracking(vector<int>& t, vector<vector<int> >& res, vector<int>& temp, int target, int sum, int index) {
		if(sum==target) res.push_back(temp);
		else {
			for(int i=index; i<t.size(); i++) {
				if(sum+t[i]<=target) {
					temp.push_back(t[i]);
					backtracking(t,res,temp,target,sum+t[i],i);
					temp.pop_back();
				}
			}
		}
		return;
	}

	vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
		vector<vector<int> > res;
		vector<int> temp;
		sort(candidates.begin(), candidates.end());
		backtracking(candidates,res,temp,target,0,0);
		return res;
	}
};

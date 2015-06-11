class Solution {
public:
	void backtracking(vector<int>& t, vector<vector<int> >& res, vector<int>& temp, int target, int sum, int index) {
		if(sum==target) {
			if(res.empty()) {res.push_back(temp); return;}
			vector<vector<int> >::iterator it = res.end()-1;
			while(it>=res.begin() && (*it)[0]==temp[0]) {
				if(temp==*it) return;
				it--;
			}
			res.push_back(temp);
		}
		else {
			for(int i=index; i<t.size(); i++) {
				if(i>0 && sum==0 && t[i]==t[i-1]) continue;
				if(sum+t[i]<=target) {
					temp.push_back(t[i]);
					backtracking(t,res,temp,target,sum+t[i],i+1);
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

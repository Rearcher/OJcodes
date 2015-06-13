struct Interval {
	int start;
	int end;
	Interval():start(0),end(0) {}
	Interval(int s, int e):start(s),end(e) {}
};

class Solution {
public:
	bool cmp(const Interval a, const Interval b) {
		return a.start<b.start;
	}
	
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> ans;
		if(intervals.empty()) return ans;
		else if(intervals.size()==1) return intervals;
	
		sort(intervals.begin(), intervals.end(), cmp);
		ans.push_back(intervals[0]);
		for(int i=1; i<intervals.size(); i++) {
			if(ans.empty() || ans.back().end<intervals[i].start) {
				ans.push_back(intervals[i]);
			}
			else if(ans.back().end < intervals[i].end){
				ans.back().end = intervals[i].end;
			}
		}
		return ans;
	}
};

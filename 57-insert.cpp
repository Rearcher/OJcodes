class Solution {
public:
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

	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		if(intervals.empty()) return vector<Interval>{newInterval};
		vector<Interval>::iterator it=intervals.begin();
		while(it!=intervals.end() && (*it).start<=newInterval.start) it++;
		intervals.insert(it, newInterval);
		return merge(intervals);
	}
};

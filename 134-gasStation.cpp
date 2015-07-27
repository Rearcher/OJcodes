class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int begin{0}, tank{0}, total{0};
		for(unsigned int i=0; i<gas.size(); i++) {
			tank += gas[i]-cost[i];
			if(tank < 0) {
				total += tank;
				tank = 0;
				begin = i+1;
			}
		}
		if(total+tank<0) return -1;
		return begin;
	}
};

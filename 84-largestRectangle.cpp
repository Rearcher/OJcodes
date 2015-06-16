class Solution {
public:
	int largestRectangleArea(vector<int>& height) {
		height.push_back(0); //important
		stack<int> s;
		int i=0, maxArea=0;
		while(i<height.size()) {
			if(s.empty() || height[i]>=height[s.top()])
				s.push(i++);
			else{
				int t=s.top();
				s.pop();
				maxArea = max(maxArea, height[t]*(s.empty()?i:i-s.top()-1));
			}
		}
		return maxArea;
	}
};

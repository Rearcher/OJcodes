class Solution {
public:
    int maxArea(vector<int>& height) {
    	int n=height.size();
    	int ans=(n-1)*min(height[0], height[n-1]);

    	int l=0, r=n-1;
    	while(l<n) {
       		if(height[l] < height[r]) l++;
       		else r--;
       		int newarea = (r-l)*min(height[l], height[r]);
       		if(newarea > ans)
       	    	ans = newarea;
    	}
    	return ans;
	}

};

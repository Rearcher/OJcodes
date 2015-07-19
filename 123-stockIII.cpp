class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if(prices.empty()) return 0;

		vector<int> profit1(prices.size(),0);
		vector<int> profit2(prices.size(),0);

		int min1 = prices[0];
		for(int i=1; i<prices.size(); i++) {
			min1 = min(min1, prices[i]);
			profit1[i] = max(profit1[i-1], prices[i]-min1);
		}

		int max2 = prices[prices.size()-1];
		for(int i=prices.size()-2; i>=0; i--) {
			max2 = max(max2, prices[i]);
			profit2[i] = max(profit2[i+1], max2-prices[i]);
		}

		int maxPro = 0;
		for(int i=0; i<prices.size(); i++) {
			if(profit1[i]+profit2[i] > maxPro)
				maxPro = profit1[i] + profit2[i];
		}
		return maxPro;
	}
};

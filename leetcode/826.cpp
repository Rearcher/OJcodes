// 826. Most Profit Assigning Work
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        for (int i = 0; i < difficulty.size(); ++i)
            jobs.push_back({difficulty[i], profit[i]});
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        
        int res = 0, i = 0, temp = 0;
        for (int w : worker) {
            while (i < jobs.size() && w >= jobs[i].first) {
                temp = max(temp, jobs[i].second);
                i++;
            }
            res += temp;
        }
        return res;
    }
};
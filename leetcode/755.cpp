// 755. Pour Water
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        for (int i = 0; i < V; ++i) {
            drop(heights, K);
        }    
        return heights;
    }

private:
    void drop(vector<int>& height, int K) {
        int i = K;

        while (i >= 0) {
            int j = i;
            while (j - 1 >= 0 && height[j - 1] == height[j]) j--;
            if (j - 1 >= 0 && height[j - 1] < height[j]) {
                i = j - 1;
            } else {
                break;
            }
        }
        if (i != K) {
            height[i] += 1;
            return;
        }

        while (i < height.size()) {
            int j = i;
            while (j + 1 < height.size() && height[j + 1] == height[j]) j++;
            if (j + 1 < height.size() && height[j + 1] < height[j]) {
                i = j + 1;
            } else {
                break;
            }
        }
        if (i != K) {
            height[i] += 1;
            return;
        }

        height[i] += 1;
    }
};

int main() {
    Solution s;
    vector<int> h{1,2,3,4,3,2,1,2,3,4,3,2,1};
    // vector<int> h{2,1,1,2,1,2,2};
    vector<int> r = s.pourWater(h, 5, 5);
    for (auto a : r) cout << a << " ";
    cout << "\n";
}
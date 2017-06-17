// 406. Queue Reconstruction by Height
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
        };
        sort(people.begin(), people.end(), cmp);
        
        vector<pair<int, int>> result;
        for (auto& p : people)
            result.insert(result.begin() + p.second, p);

        return result;
    }
};

int main() {

}
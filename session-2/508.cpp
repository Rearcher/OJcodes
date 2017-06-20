// 508. Most Frequent Subtree Sum
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        unordered_map<int, int> m;
        iterate(root, m);

        int max_sum = 0;
        for (const auto& kv : m)
            max_sum = max(max_sum, kv.second);
        for (const auto& kv : m)
            if (kv.second == max_sum)
                result.push_back(kv.first);

        return result;
    }

private:
    int iterate(TreeNode* root, unordered_map<int, int>& m) {
        int left = 0, right = 0, result = root->val;
        if (root->left) left = iterate(root->left, m);
        if (root->right) right = iterate(root->right, m);

        result += left + right;
        if (m.count(result)) {
            m[result] += 1;
        } else {
            m[result] = 1;
        }

        return result;
    }
};

int main() {

}
// 863. All Nodes Distance K in Binary Tree
#include "leetcode.hpp"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (K == 0) return vector<int>{target->val};

        buildGraph(root);

        int start = target->val;
        unordered_set<int> visited;
        visited.insert(start);

        vector<int> res = edgeList[start];
        for (int i = 1; i < K; ++i) {
            vector<int> tmp;
            for (int node : res) {
                if (visited.count(node)) continue;
                visited.insert(node);
                for (int n : edgeList[node])
                    if (!visited.count(n)) tmp.push_back(n);
            }
            res = vector<int>(tmp);
        }
        return res;
    }

private:
    void buildGraph(TreeNode* root) {
        if (!root) return;
        if (root->left) {
            edgeList[root->val].push_back(root->left->val);
            edgeList[root->left->val].push_back(root->val);
            buildGraph(root->left);
        }
        if (root->right) {
            edgeList[root->val].push_back(root->right->val);
            edgeList[root->right->val].push_back(root->val);
            buildGraph(root->right);
        }
    }

    unordered_map<int, vector<int>> edgeList;
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    Solution s;
    vector<int> res = s.distanceK(root, root->left, 2);
    for (auto r : res) cout << r << " ";
}
// 742. Closest Leaf in a Binary Tree
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<int, vector<int>> graph;
        unordered_set<int> leaves;
        traverse(root, graph, leaves);

        vector<int> q{k};
        while (!q.empty()) {
            vector<int> next;
            for (auto n : q) {
                if (leaves.count(n)) return n;
                next.insert(next.end(), graph[n].begin(), graph[n].end());
                graph.erase(n);
            }
            q = next;
        }

        return k;
    }

private:
    void traverse(TreeNode* root, unordered_map<int, vector<int>>& graph, unordered_set<int>& leaves) {
        if (root == nullptr) return;

        if (root->left == nullptr && root->right == nullptr) {
            leaves.insert(root->val);
            return;
        }

        if (root->left) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            traverse(root->left, graph, leaves);
        }

        if (root->right) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            traverse(root->right, graph, leaves);
        }
    }
};

int main() {

}
// 501. Find Mode in Binary Search Tree
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> findMode(TreeNode* root) {        
        vector<int> result;

        if (root == NULL) {
            return result;
        }

        int last, max_cnt = 0, cur_cnt = 0;
        TreeNode* tmp = root;
        while (tmp && tmp->left) {
            tmp = tmp->left;
        }
        last = tmp->val - 1;

        firstTraversal(root, last, max_cnt, cur_cnt);
        max_cnt = max(max_cnt, cur_cnt);

        last = tmp->val - 1;
        cur_cnt = 0;
        secondTraversal(root, last, max_cnt, cur_cnt, result);
        if (cur_cnt == max_cnt) {
            result.push_back(last);
        }

        return result;
    }

private:
    void firstTraversal(TreeNode* root, int& last, int& max_cnt, int& cur_cnt) {
        if (root == NULL) {
            return;
        }

        firstTraversal(root->left, last, max_cnt, cur_cnt);
        
        if (root->val == last) {
            cur_cnt += 1;
        } else {
            max_cnt = max(max_cnt, cur_cnt);
            cur_cnt = 1;
            last = root->val;
        }

        firstTraversal(root->right, last, max_cnt, cur_cnt);
    }

    void secondTraversal(TreeNode* root, int& last, int max_cnt, int& cur_cnt, vector<int>& result) {
        if (root == NULL) {
            return;
        }

        secondTraversal(root->left, last, max_cnt, cur_cnt, result);

        if (root->val == last) {
            cur_cnt += 1;
        } else {
            if (cur_cnt == max_cnt)
                result.push_back(last);
            cur_cnt = 1;
            last = root->val;
        }

        secondTraversal(root->right, last, max_cnt, cur_cnt, result);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);

    Solution s;
    vector<int> result = s.findMode(root);
    for (int n : result)
        cout << n << " ";
    cout << endl;
}
// 653. Two Sum IV - Input is a BST
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        
        vector<int> seq;
        stack<TreeNode*> st;
        TreeNode* cur = root;

        while (cur || st.size()) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                TreeNode* tmp = st.top();
                st.pop();
                seq.push_back(tmp->val);
                if (tmp->right) cur = tmp->right;
            }
        }

        int i = 0, j = seq.size() - 1;
        while (i < j) {
            int sum = seq[i] + seq[j];
            if (sum == k) return true;
            else if (sum < k) i++;
            else j--;
        }

        return false;
    }
};

int main() {

}
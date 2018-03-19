// 783. Minimum Distance Between BST Nodes
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        vector<int> vals;
        int result = INT_MAX;

        while (cur || st.size()) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                TreeNode* tmp = st.top();
                st.pop();
                if (vals.size())
                    result = min(result, tmp->val - vals.back());
                vals.push_back(tmp->val);
                cur = tmp->right;
            }
        }

        return result;
    }
};

int main() {

}
// 98. Validate Binary Search Tree
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        vector<int> seq;

        while (cur || st.size()) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                TreeNode* tmp = st.top();
                st.pop();

                if (seq.size() && seq.back() >= tmp->val)
                    return false;
                seq.push_back(tmp->val);

                if (tmp->right) {
                    cur = tmp->right;
                }
            }
        }

        return true;
    }
};

int main() {

}
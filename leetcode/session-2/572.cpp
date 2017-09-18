// 572. Subtree of Another Tree
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL) {
            return t == NULL ? true : false;
        }

        if (t == NULL) {
            return true;
        }

        stack<TreeNode*> st;
        st.push(s);

        while (!st.empty()) {
            TreeNode* tmp = st.top();
            st.pop();

            if (tmp->val == t->val && isSame(tmp, t)) {
                return true;
            }

            if (tmp->right)
                st.push(tmp->right);
            if (tmp->left)
                st.push(tmp->left);
        }

        return false;
    }

private:
    bool isSame(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL) {
            return true;
        }

        if (s != NULL && t != NULL) {
            if (s->val != t->val) {
                return false;
            }

            return isSame(s->left, t->left) && isSame(s->right, t->right);
        }

        return false;
    }
};

int main() {
    TreeNode* s = new TreeNode(3);
    s->left = new TreeNode(4);
    s->right = new TreeNode(5);
    s->left->left = new TreeNode(1);
    s->left->right = new TreeNode(2);
    s->left->right->left = new TreeNode(0);

    TreeNode* t = new TreeNode(4);
    t->left = new TreeNode(1);
    t->right = new TreeNode(2);

    Solution solution;
    cout << solution.isSubtree(s, t) << endl;
}
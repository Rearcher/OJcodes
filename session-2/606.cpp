// 606. Constructing String from Binary Tree
#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    string tree2str(TreeNode* t) {
        if (t == NULL) {
            return "";
        }

        string result = to_string(t->val);
        string left = tree2str(t->left);
        string right = tree2str(t->right);

        if (left == "" && right == "") {
            return result;
        }

        if (left == "") {
            return result + "()" + "(" + right + ")";
        }

        if (right == "") {
            return result + "(" + left + ")";
        }

        return result + "(" + left + ")" + "(" + right + ")";
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    cout << s.tree2str(root) << endl;
}
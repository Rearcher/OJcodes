// 449. Serialize and Deserialize BST
#include "leetcode.hpp"
using namespace std;

class Codec {
public:
    string serialize(TreeNode* root) {
        string result = "";
        if (!root) return result;
        stack<TreeNode*> s;

        s.push(root);
        while (!s.empty()) {
            TreeNode* tmp = s.top();
            s.pop();
            if (result.size() > 0) result += ",";
            result += to_string(tmp->val);

            if (tmp->right) s.push(tmp->right);
            if (tmp->left) s.push(tmp->left);
        }

        return result;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        vector<int> vals;

        string tmp;
        while (getline(ss, tmp, ',')) {
            vals.push_back(stoi(tmp));
        }

        return buildTree(vals);
    }

private:
    TreeNode* buildTree(vector<int>& vals) {
        if (vals.empty()) return NULL;

        TreeNode* root = new TreeNode(vals[0]);
        if (vals.size() == 1) return root;

        vector<int> leftVals, rightVals;
        for (int i = 1; i < vals.size(); ++i) {
            if (vals[i] < root->val) {
                leftVals.push_back(vals[i]);
            } else {
                rightVals.push_back(vals[i]);
            }
        }
        root->left = buildTree(leftVals);
        root->right = buildTree(rightVals);

        return root;
    }
};

int main() {

}
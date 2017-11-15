// 725. Split Linked List in Parts
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode *iter = root;
        int len = 0;

        while (iter) {
            iter = iter->next;
            len++;
        }

        vector<int> s(k, len / k);
        for (int i = 0; i < len % k; ++i)
            s[i]++;
        
        iter = root;
        vector<ListNode*> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(iter);

            int cur = s[i];
            ListNode* prev;
            while (cur) {
                prev = iter;
                iter = iter->next;
                cur--;
            }
            prev->next = nullptr;
        }

        return result;
    }
};

int main() {
    ListNode* root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);

    Solution s;
    vector<ListNode*> res = s.splitListToParts(root, 5);
    for (auto h : res) {
        auto i = h;
        while (i) {
            cout << i->val << " ";
            i = i->next;
        }
        cout << "\n";
    }
}
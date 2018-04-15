// 817. Linked List Components
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> nums(G.begin(), G.end());
        ListNode* temp = head;
        int res = 0;
        bool last = false;

        while (temp) {
            if (nums.count(temp->val)) {
                if (!last) {
                    res += 1;
                    nums.erase(temp->val);
                }
                last = true;
            } else {
                last = false;
            }
            temp = temp->next;
        }

        return res;      
    }
};

int main() {
    ListNode* head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);

    vector<int> G{0, 1, 3, 4};
    Solution s;
    cout << s.numComponents(head, G) << "\n";
}
// 382. Linked List Random Node
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    Solution(ListNode* head) {
        this->head = head;
        srand(time(0));
    }

    int getRandom() {
        int result = head->val, i = 2;
        ListNode* node = head->next;

        while (node) {
            int j = rand() % i;
            if (j == 0) result = node->val;
            i++;
            node = node->next;
        }

        return result;
    }

private:
    ListNode* head;
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    Solution s(head);
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
}
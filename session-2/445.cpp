// 445. Add Two Numbers II
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> a, b;

        ListNode* tmp = l1;
        while (tmp) {
            a.push(tmp->val);
            tmp = tmp->next;
        }

        tmp = l2;
        while (tmp) {
            b.push(tmp->val);
            tmp = tmp->next;
        }

        int sum = 0;
        ListNode* head = new ListNode(0);
        while (!a.empty() || !b.empty()) {
            if (!a.empty()) {
                sum += a.top();
                a.pop();
            }

            if (!b.empty()) {
                sum += b.top();
                b.pop();
            }

            head->val = sum % 10;
            ListNode* newHead = new ListNode(sum / 10);
            newHead->next = head;
            head = newHead;
            sum /= 10;
        }

        return head->val == 0 ? head->next : head;
    }
};

int main() {

}
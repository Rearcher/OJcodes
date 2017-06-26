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

        ListNode* fakeHead = new ListNode(0), *curNode = NULL;

        int carry = 0;
        while (!a.empty() && !b.empty()) {
            int digit = a.top() + b.top() + carry;
            carry = digit / 10;
            digit = digit % 10;
            
            ListNode* tmpNode = new ListNode(digit);
            fakeHead->next = tmpNode;
            tmpNode->next = curNode;
            curNode = tmpNode;

            a.pop();
            b.pop();
        }

        while (!a.empty()) {
            int digit = a.top() + carry;
            carry = digit / 10;
            digit = digit % 10;

            ListNode* tmpNode = new ListNode(digit);
            fakeHead->next = tmpNode;
            tmpNode->next = curNode;
            curNode = tmpNode;

            a.pop();
        }

        while (!b.empty()) {
            int digit = b.top() + carry;
            carry = digit / 10;
            digit = digit % 10;

            ListNode* tmpNode = new ListNode(digit);
            fakeHead->next = tmpNode;
            tmpNode->next = curNode;
            curNode = tmpNode;

            b.pop();
        }

        if (carry > 0) {
            ListNode* tmpNode = new ListNode(carry);
            fakeHead->next = tmpNode;
            tmpNode->next = curNode;
            curNode = tmpNode;
        }

        return fakeHead->next;
    }
};

int main() {

}
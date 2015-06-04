#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* res = new ListNode(0); //without init, it was RE!
		ListNode* a = l1;
		ListNode* b = l2;
		int sum = (*a).val + (*b).val;
		(*res).val = sum%10;
		ListNode* c = res;
		int carry = sum/10;
		while((*a).next != NULL && (*b).next != NULL) {
			a = (*a).next;
			b = (*b).next;
			sum = (*a).val + (*b).val + carry;
			(*c).next = new ListNode(sum%10, NULL);
			c = (*c).next;
			carry = sum/10;
		}
		while((*a).next != NULL) {
			a = (*a).next;
			sum = (*a).val + carry;
			(*c).next = new ListNode(sum%10, NULL);
			c = (*c).next;
			carry = sum/10;
		}
		while((*b).next != NULL) {
			b = (*b).next;
			sum = (*b).val + carry;
			(*c).next = new ListNode(sum%10, NULL);
			c = (*c).next;
			carry = sum/10;
		}
		if(carry != 0) {
			(*c).next = new ListNode(carry, NULL);
		}
		return res;
}

int main() {
	
}

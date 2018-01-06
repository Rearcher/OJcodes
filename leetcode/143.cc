#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void reorderList(ListNode* head) {
		ListNode *cur = head;
		vector<ListNode*> nodes;

		while (cur) {
			nodes.push_back(cur);
			cur = cur->next;
			nodes.back()->next = nullptr;
		}

		int i = 0, j = nodes.size() - 1;
		ListNode *prev = new ListNode(0);
		while (i < j) {
			prev->next = nodes[i];
			nodes[i]->next = nodes[j];
			prev = nodes[j];

			i++;
			j--;
		}
		if (i == j) prev->next = nodes[i];
	}
};

int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	(new Solution())->reorderList(head);
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
}

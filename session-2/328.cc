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
	/* my stupid solution */
    ListNode* oddEvenList(ListNode* head) {
         ListNode *fakeRoot = new ListNode(0);
        fakeRoot->next = head;
        int numNodes = 0;
        
        ListNode *tail, *cur = head;
        while (cur) {
            if (cur->next == nullptr) tail = cur;
            cur = cur->next;
            numNodes++;
        }
        
        ListNode *prev = fakeRoot; 
        cur = fakeRoot->next;
        int cnt = 1;
        while (cnt <= numNodes) {
            if (cnt%2 == 0) {
                if (tail == cur) break;
                prev->next = cur->next;
                
                tail->next = cur;
                cur->next = nullptr;
                tail = tail->next;
                
                cur = prev->next;
            } else {
                prev = cur;
                cur = cur->next;
            }
            cnt++;
        }
        
        return head;
    }

	/* nice solution */
	ListNode *oddEvenList_ex(ListNode* head) {
		if (!head) return head;
		ListNode *odd = head, *evenhead = head->next, *even = evenhead;
		while (even && even->next) {
			odd->next = odd->next->next;
			even->next = even->next->next;

			odd = odd->next;
			even = even->next;
		}
		odd->next = evenhead;
		return head;
	}
};

int main() {
	Solution s;
	ListNode *head = new ListNode(1);
	ListNode *p = head;
	vector<int> a{2, 3};

	for (auto num : a) {
		p->next = new ListNode(num);
		p = p->next;
	}

	p = s.oddEvenList_ex(head);
	while (p) {
		cout << p->val << endl;
		p = p->next;
	}
}

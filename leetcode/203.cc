/* remove linked list elements */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *fake_root = new ListNode(0);
        fake_root->next = head;
        
        ListNode *p = fake_root, *q = head;
        while (q != nullptr) {
            if (q->val == val) {
                ListNode *temp = q;
                p->next = q->next;
                q = q->next;
                delete temp;
                continue;
            }
            q = q->next;
            p = p->next;
        }
        return fake_root->next;
    }
};

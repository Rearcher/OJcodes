/* delete a node in a linked list */

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
    void deleteNode(ListNode* node) {
        ListNode *pNode = node->next;
        node->val = pNode->val;
        node->next = pNode->next;
        delete pNode;
    }
};

/* reverse linklist */
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
    ListNode* reverseList(ListNode* head) {
       ListNode *reverseHead = nullptr;
       ListNode *pNode = head;
       ListNode *pPrev = nullptr, *pNext;
       
       while (pNode) {
           pNext = pNode->next;
           
           if (pNext == nullptr) reverseHead = pNode;
           pNode->next = pPrev;
           
           pPrev = pNode;
           pNode = pNext;
       }
       return reverseHead;
    }
};

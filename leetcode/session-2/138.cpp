// 138. Copy List with Random Pointer
#include "leetcode.hpp"
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *iter = head, *next;

        while (iter) {
            next = iter->next;

            RandomListNode *copy = new RandomListNode(iter->label);
            iter->next = copy;
            copy->next = next;

            iter = next;
        }

        iter = head;
        while (iter) {
            if (iter->random)
                iter->next->random = iter->random->next;

            iter = iter->next->next;
        }

        iter = head;
        RandomListNode *fakeHead = new RandomListNode(0);
        RandomListNode *copy, *iter2 = fakeHead;
        while (iter) {
            next = iter->next->next;
            
            copy = iter->next;
            iter2->next = copy;
            iter2 = copy;

            iter->next = next;
            iter = next;
        }

        return fakeHead->next;
    }
};
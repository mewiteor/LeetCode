#ifndef _HEAD_H_
#define _HEAD_H_

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

#endif // _HEAD_H_

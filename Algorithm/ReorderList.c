/*
 * Copyright (C) 2016  Mewiteor <mewiteor@hotmail.com>
 * 
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

/*
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You must do this in-place without altering the nodes' values.
 *
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */


/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* findMiddle(struct ListNode* head);
struct ListNode* reverse(struct ListNode* head);
void merge(struct ListNode* left,struct ListNode* right);

void reorderList(struct ListNode* head) {
    struct ListNode *p,*q;
    if(!head||!head->next||!head->next->next)
        return;
    p=findMiddle(head);
    q=reverse(p->next);
    p->next=NULL;
    merge(head,q);
}
 
// get n/2
struct ListNode* findMiddle(struct ListNode* head) {
    struct ListNode *p=head,*q=head;
    while(q&&q->next) {
        p=p->next;
        q=q->next->next;
    }
    return p;
}

struct ListNode* reverse(struct ListNode* head) {
    struct ListNode *p,*q,*r;
    p=head;
    if(!p)
        return NULL;
    q=p->next;
    if(!q)
        return head;
    r=q->next;
    p->next=NULL;
    q->next=p;
    while(r){
        p=q;q=r;r=r->next;
        q->next=p;
    }
    return q;
}

// length(right)<=length(left)
void merge(struct ListNode* left,struct ListNode* right) {
    struct ListNode *t;
    while(right) {
        t=right->next;
        right->next=left->next;
        left->next=right;
        right=t;
        left=left->next->next;
    }
}
 


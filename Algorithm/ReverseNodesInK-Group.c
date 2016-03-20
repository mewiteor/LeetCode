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
 * Given a linked list, reverse the nodes of a linked list k at a
 * time and return its modified list.
 *
 * If the number of nodes is not a multiple of k then left-out nodes
 * in the end should remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself
 * may be changed.
 *
 * Only constant memory is allowed.
 *
 * For example,
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
 */

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* tmp=head,*p,*q,*r,*s;
    int len=0,i,j;
    while(tmp){++len;tmp=tmp->next;}
    if(len<2||k>len||k<2)return head;
    tmp=head;
    head=NULL;
    for(i=len/k;i>0;--i) {
        if(2==k) {
            p=head?tmp->next:tmp;
            q=p->next;
            p->next=q->next;
            q->next=p;
            if(!head)head=q;
            else tmp->next=q;
            tmp=p;
        } else {
            s=p=head?tmp->next:tmp;
            q=p->next;
            r=q->next;
            j=0;
            while(j<k-1) {
                if(j++){p=q;q=r;r=r->next;}
                q->next=p;
            }
            if(!head)head=q;
            else tmp->next=q;
            s->next=r;
            tmp=s;
            s=r;
        }
    }
    return head;
}

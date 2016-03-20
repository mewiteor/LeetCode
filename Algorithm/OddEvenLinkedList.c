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
 * Given a singly linked list, group all odd nodes together followed
 * by the even nodes. Please note here we are talking about the node
 * number and not the value in the nodes.
 *
 * You should try to do it in place. The program should run in O(1)
 * space complexity and O(nodes) time complexity.
 *
 * Example:
 * Given 1->2->3->4->5->NULL,
 * return 1->3->5->2->4->NULL.
 *
 * Note:
 * The relative order inside both the even and odd groups should
 * remain as it was in the input. 
 * The first node is considered odd, the second node even and so on ...
 *
 */

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode *hh,*p=head,*q,*t=head;
    if(!head||!head->next)
        return head;
    q=hh=head->next;
    for(;;) {
        p=p->next=q->next;
        if(!p)
            break;
        t=p;
        q=q->next=p->next;
        if(!q)
            break;
    }
    t->next=hh;
    return head;
}

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
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 * For example,
 *
 *    Given linked list: 1->2->3->4->5, and n = 2.
 *
 *    After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 *       Given n will always be valid.
 *       Try to do this in one pass.
 */

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int len=0;
    struct ListNode* tmp=head,*tmp2;
    while(tmp) {
        ++len;
        tmp=tmp->next;
    }
    n=len-n;
    if(n<0||n>=len)return head;
    else if(!n) {
        tmp=head->next;
        free(head);
        return tmp;
    }
    tmp=head;
    while(--n)tmp=tmp->next;
    tmp2=tmp->next;
    tmp->next=tmp2->next;
    free(tmp2);
    return head;
}

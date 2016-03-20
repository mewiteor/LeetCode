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
 * Sort a linked list in O(n log n) time using constant space complexity.
 */

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* merge(struct ListNode* head1,struct ListNode* head2) {
    struct ListNode* head,*tmp;
    if(head1->val<head2->val) {
        head=head1;
        head1=head1->next;
    } else {
        head=head2;
        head2=head2->next;
    }
    tmp=head;
    while(head1&&head2) {
        if(head1->val<head2->val) {
            tmp->next=head1;
            head1=head1->next;
        } else {
            tmp->next=head2;
            head2=head2->next;
        }
        tmp=tmp->next;
    }
    if(head1)
        tmp->next=head1;
    else if(head2)
        tmp->next=head2;
    return head;
}
struct ListNode* mergeSort(struct ListNode* head,size_t len) {
    if(len<2) {
        head->next=NULL;
        return head;
    } else {
        size_t len1=len>>1,len2=len-len1,i;
        struct ListNode* head1=head,*head2=head;
        i=len1;
        while(i--)
            head2=head2->next;
        head1=mergeSort(head1,len1);
        head2=mergeSort(head2,len2);
        return merge(head1,head2);
    }
}
struct ListNode* sortList(struct ListNode* head) {
    size_t len=0;
    struct ListNode* tmp=head;
    while(tmp) {
        ++len;
        tmp=tmp->next;
    }
    if(len<2)
        return head;
    return mergeSort(head,len);
}

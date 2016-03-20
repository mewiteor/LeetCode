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
 * Sort a linked list using insertion sort.
 */

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode* tmp1,*tmp2,*tmp3,th,*pth=&th;
    if(!head||!head->next)
        return head;
    tmp1=head->next;
    head->next=NULL;
    th.next=head;
    while(tmp1) {
        tmp2=pth;
        while(tmp2->next&&tmp2->next->val<tmp1->val)
            tmp2=tmp2->next;
        tmp3=tmp1;
        tmp1=tmp1->next;
        tmp3->next=tmp2->next;
        tmp2->next=tmp3;
    }
    return pth->next;
}

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
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of
 * the first two lists.
 */

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(!l1)return l2;
	else if(!l2)return l1;
	else {
		struct ListNode* ret,*tmp;
		if(l1->val>l2->val){ret=l2;l2=l2->next;}
		else{ret=l1;l1=l1->next;}
		tmp=ret;
		while(l1&&l2)
		{
			if(l1->val>l2->val){tmp->next=l2;l2=l2->next;}
			else{tmp->next=l1;l1=l1->next;}
			tmp=tmp->next;
		}
		if(l1)tmp->next=l1;
		else if(l2)tmp->next=l2;
		return ret;
	}
}

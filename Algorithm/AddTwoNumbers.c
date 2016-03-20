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
 *     You are given two linked lists representing two non-negative numbers.
 *     The digits are stored in reverse order and each of their nodes contain a single digit.
 *     Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* lnhead=(struct ListNode*)calloc(1,sizeof(struct ListNode)),*lncur=lnhead;
	unsigned char r=0;
	while(l1||l2||r){
		lncur=lncur->next=(struct ListNode*)calloc(1,sizeof(struct ListNode));
		lncur->val=(l1?l1->val:0)+(l2?l2->val:0)+r;
		if(lncur->val<=9)r=0;
		else{r=1;lncur->val-=10;}
		if(l1)l1=l1->next;
		if(l2)l2=l2->next;
	}
	lncur=lnhead->next;
	free(lnhead);
	return lncur;
}

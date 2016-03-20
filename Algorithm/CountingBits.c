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
 * Given a non negative integer number num. For every numbers i in
 * the range 0 ≤ i ≤ num calculate the number of 1's in their binary
 * representation and return them as an array.
 *
 * Example:
 * For num = 5 you should return [0,1,1,2,1,2].
 *
 * Follow up:
 *
 * It is very easy to come up with a solution with run time O(n*sizeof(integer)).
 * But can you do it in linear time O(n) /possibly in a single pass?
 * Space complexity should be O(n).
 * Can you do it like a boss? Do it without using any builtin function like
 * __builtin_popcount in c++ or in any other language.
 * Hint:
 *
 * You should make use of what you have produced already.
 * Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on.
 * And try to generate new range from previous.
 * Or does the odd/even status of the number help you in calculating the number of 1s?
 */

/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
    int *ret=(int*)malloc(sizeof(int)*(*returnSize=num+1)),i;
	ret[0]=0;
	for(i=1;i<=num;++i)
		ret[i]=ret[i&i-1]+1;
	return ret;
}

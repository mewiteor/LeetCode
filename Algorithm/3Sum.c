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
 * Given an array S of n integers, are there elements a, b, c in S such
 * that a + b + c = 0? Find all unique triplets in the array which gives
 * the sum of zero.
 *
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 *     For example, given array S = {-1 0 1 2 -1 -4},
 *
 *         A solution set is:
 *             (-1, 0, 1)
 *                 (-1, -1, 2)
 */

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* a,const void* b) {
	return *(int*)a-*(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
	int allsz=(numsSize-1)*(numsSize-1)>>2;
	int** rt=(int**)malloc(allsz*sizeof(int*)),
		i,j,k;
	for(i=0;i<allsz;++i)
		rt[i]=(int*)malloc(3*sizeof(int));
	*returnSize=0;
	qsort(nums,numsSize,sizeof(int),cmp);
	if(nums[0]>0||nums[numsSize-1]<0)return rt;
	for(i=0;nums[i]<=0;++i)
	{
		j=i+1;k=numsSize-1;
		while(j<k)
		{
			if(nums[j]+nums[k]==-nums[i])
			{
				rt[*returnSize][0]=nums[i];
				rt[*returnSize][1]=nums[j];
				rt[*returnSize][2]=nums[k];
				++*returnSize;
				while(nums[j]==nums[j+1])++j;
				++j;
				while(nums[k]==nums[k-1])--k;
				--k;
			}
			else if(nums[j]+nums[k]<-nums[i])++j;
			else --k;
		}
		while(nums[i]==nums[i+1])++i;
	}
	return rt;
}

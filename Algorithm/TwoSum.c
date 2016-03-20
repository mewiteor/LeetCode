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
 *  Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *
 *  You may assume that each input would have exactly one solution.
 *
 * Example:
 *      Given nums = [2, 7, 11, 15], target = 9,
 *
 *      Because nums[0] + nums[1] = 2 + 7 = 9,
 *      return [0, 1].
 *
 * UPDATE (2016/2/13):
 *  The return format had been changed to zero-based indices. Please read the above updated description carefully.
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int comp(const void* a,const void* b){return (*(int(*)[2])a)[0]-(*(int(*)[2])b)[0];}
int* twoSum(int* nums, int numsSize, int target) {
	int (*tmp)[2]=(int(*)[2])malloc(numsSize*sizeof(int[2]));
	int *r=(int*)malloc(2*sizeof(int));
	int (*a)[2]=tmp,(*b)[2]=tmp+numsSize-1,i;
	for(i=0;i<numsSize;++i){tmp[i][0]=nums[i];tmp[i][1]=i;}
	qsort(tmp,numsSize,sizeof(int[2]),comp);
	while(a<b&&(*a)[0]+(*b)[0]!=target){
		if((*a)[0]+(*b)[0]<target)++a;
		else --b;
	}
	r[0]=(*a)[1]+1;
	r[1]=(*b)[1]+1;
	if(r[0]>r[1]){i=r[0];r[0]=r[1];r[1]=i;}
	free(tmp);
	return r;
}

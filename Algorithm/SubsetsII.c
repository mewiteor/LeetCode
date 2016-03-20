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
 * Given a collection of integers that might contain duplicates,
 * nums, return all possible subsets.
 * 
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * For example,
 * If nums = [1,2,2], a solution is:
 * 
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
 *   [1,2],
 *   []
 * ]
 */

int cmp(const void *a,const void *b) {
    return *(int*)a-*(int*)b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsetsWithDup(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    int **ret,i,j,size=0;
    qsort(nums,numsSize,sizeof(int),cmp);
    *columnSizes=(int*)calloc(*returnSize=1,sizeof(int));
    *(ret=(int**)malloc(sizeof(int*)))=(int*)malloc(0);
    for(i=0;i<numsSize;++i)
        for(j=i>=1&&nums[i]==nums[i-1]?size:0,size=*returnSize;j<size;++j) {
            ret=(int**)realloc(ret,++*returnSize*sizeof(int*));
            *columnSizes=(int*)realloc(*columnSizes,*returnSize*sizeof(int));
            ret[*returnSize-1]=(int*)malloc(((*columnSizes)[*returnSize-1]=(*columnSizes)[j]+1)*sizeof(int));
            memcpy(ret[*returnSize-1],ret[j],sizeof(int)*(*columnSizes)[j]);
            ret[*returnSize-1][(*columnSizes)[j]]=nums[i];
        }
    return ret;
}

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
 * Given a set of distinct integers, nums, return all possible subsets.
 * 
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * For example,
 * If nums = [1,2,3], a solution is:
 * 
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 */

int comp(const void *a,const void *b) {
    return *(int*)a-*(int*)b;
}

/*
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    int i,j;
    int **r=(int**)malloc(sizeof(int*)*(*returnSize=1<<numsSize));
    *columnSizes=(int*)calloc(*returnSize,sizeof(int));
    
    qsort(nums,numsSize,sizeof(int),comp);
    for(i=0;i<*returnSize;++i) {
        r[i]=(int*)malloc(0);
        for(j=0;1<<j<=i;++j)
            if(1<<j&i){
                r[i]=(int*)realloc(r[i],++(*columnSizes)[i]*sizeof(int));
                r[i][(*columnSizes)[i]-1]=nums[j];
            }
    }
    return r;
}

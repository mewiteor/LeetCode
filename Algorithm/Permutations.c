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
 * Given a collection of distinct numbers, return all possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 */

/*
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int comp(const void* a,const void* b){return *(int*)a-*(int*)b;}
int** permute(int* nums, int numsSize, int* returnSize) {
    switch(numsSize) {
        case 0:*returnSize=0;return malloc(0);
        case 1:{
            *returnSize=1;
            int **ret=(int**)malloc(sizeof(int*));
            ret[0]=(int*)malloc(sizeof(int)*numsSize);
            memcpy(ret[0],nums,sizeof(int)*numsSize);
            return ret;
        }
        default: {
            // n!
            int **ret;
            int *j,*p,*q;
            int t,i;
            *returnSize=1;
            for(i=2;i<=numsSize;++i)*returnSize*=i;
            qsort(nums,numsSize,sizeof(int),comp);
            ret=(int**)malloc(*returnSize*sizeof(int*));
            ret[0]=(int*)malloc(numsSize*sizeof(int));
            memcpy(ret[0],nums,sizeof(int)*numsSize);
            for(i=1;i<*returnSize;++i) {
                p=j=(q=nums+numsSize)-1;
                while(*--j>=*p)p=j;
                while(*j>=*--q);
                t=*j;*j=*q;*q=t;
                for(q=nums+numsSize-1;p<q;++p,--q) {t=*p;*p=*q;*q=t;}
                ret[i]=(int*)malloc(numsSize*sizeof(int));
                memcpy(ret[i],nums,numsSize*sizeof(int));
            }
            return ret;
        }
    }
}

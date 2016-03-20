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
 * Given a collection of numbers that might contain duplicates,
 * return all possible unique permutations.
 *
 * For example,
 * [1,1,2] have the following unique permutations:
 * [1,1,2], [1,2,1], and [2,1,1].
 */

/*
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int comp(const void* a,const void* b){return *(int*)a-*(int*)b;}
int** permuteUnique(int* nums, int numsSize, int* returnSize) {
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
            int **ret;
            int *j,*p,*q;
            int t,i;
            *returnSize=1;
            qsort(nums,numsSize,sizeof(int),comp);
            ret=(int**)malloc(sizeof(int*));
            ret[0]=(int*)malloc(numsSize*sizeof(int));
            memcpy(ret[0],nums,sizeof(int)*numsSize);
            while(1) {
                p=j=(q=nums+numsSize)-1;
                while(--j>=nums&&*j>=*p)p=j;
                if(j<nums)break;
                while(*j>=*--q);
                t=*j;*j=*q;*q=t;
                for(q=nums+numsSize-1;p<q;++p,--q) {t=*p;*p=*q;*q=t;}
                
                ret=(int**)realloc(ret,++*returnSize*sizeof(int*));
                ret[*returnSize-1]=(int*)malloc(numsSize*sizeof(int));
                memcpy(ret[*returnSize-1],nums,numsSize*sizeof(int));
            }
            return ret;
        }
    }
}


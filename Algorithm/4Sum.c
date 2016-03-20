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
 * Given an array S of n integers, are there elements a, b, c, and d
 * in S such that a + b + c + d = target? Find all unique quadruplets
 * in the array which gives the sum of target.
 *
 * Note:
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order.
 * (ie, a ≤ b ≤ c ≤ d)
 * The solution set must not contain duplicate quadruplets.
 *     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 *
 *         A solution set is:
 *             (-1,  0, 0, 1)
 *             (-2, -1, 1, 2)
 *             (-2,  0, 0, 2)
 */

int cmp(const void *a,const void *b) {
    return *(int*)a-*(int*)b;
}

int lower_bound(const int *array,int start,int end,const int value) {
    int i;
    while(start<end) {
        i=start+((end-start)>>1);
        if(array[i]<value)
            start=i+1;
        else
            end=i;
    }
    return start;
}

void ksum_sub(int *nums,int numsSize,int start,int target,int k,int ***ret,int *retSize,int *index,int index_i,int index_sz) {
    if(k==2) {
        int i,j=numsSize-1,t;
        i=lower_bound(nums,start,numsSize,target-nums[j]);
        while(i<j) {
            if(nums[i]+nums[j]==target) {
                index[index_sz-2]=i;
                index[index_sz-1]=j;
                *ret=(int**)realloc(*ret,sizeof(int*)*(*retSize+1));
                (*ret)[*retSize]=(int*)malloc(sizeof(int)*index_sz);
                for(t=0;t<index_sz;++t)
                    (*ret)[*retSize][t]=nums[index[t]];
                ++*retSize;
                do{++i;}while(i<j&&nums[i-1]==nums[i]);
                do{--j;}while(i<j&&nums[j]==nums[j+1]);
            }
            else if(nums[i]+nums[j]<target)
                do{++i;}while(i<j&&nums[i-1]==nums[i]);
            else
                do{--j;}while(i<j&&nums[j]==nums[j+1]);
        }
    } else {
        int i=k,sum=0;
        while(--i)
            sum+=nums[numsSize-i];
        index[index_i]=lower_bound(nums,start,numsSize-k+1,target-sum);
        if(index[index_i]==numsSize-k+1)
            return;
        for(sum=0,i=0;i<k;++i)
            sum+=nums[index[index_i]+i];
        while(sum<target) {
            ksum_sub(nums,numsSize,index[index_i]+1,target-nums[index[index_i]],k-1,ret,retSize,index,index_i+1,index_sz);
            do {
                sum=sum-nums[index[index_i]]+nums[index[index_i]+k];
                ++index[index_i];
            }while(index[index_i]<=numsSize-k&&nums[index[index_i]-1]==nums[index[index_i]]);
        }
        if(sum==target) {
                *ret=(int**)realloc(*ret,sizeof(int*)*(*retSize+1));
                (*ret)[*retSize]=(int*)malloc(sizeof(int)*index_sz);
                for(i=index_i+1;i<index_sz;++i)
                    index[i]=index[i-1]+1;
                for(i=0;i<index_sz;++i)
                    (*ret)[*retSize][i]=nums[index[i]];
                ++*retSize;
        }
    }
}

int **ksum(int *nums,int numsSize,int target,int k,int *returnSize) {
    int **ret=(int**)malloc(*returnSize=0);
    int *index;
    if(numsSize<k)return ret;
    index=(int*)malloc(sizeof(int)*k);
    qsort(nums,numsSize,sizeof(int),cmp);
    ksum_sub(nums,numsSize,0,target,k,&ret,returnSize,index,0,k);
    free(index);
    return ret;
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    return ksum(nums,numsSize,target,4,returnSize);
}

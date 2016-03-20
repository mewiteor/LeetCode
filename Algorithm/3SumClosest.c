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
 * Given an array S of n integers, find three integers in S such
 * that the sum is closest to a given number, target. Return the
 * sum of the three integers. You may assume that each input would
 * have exactly one solution.
 *
 *     For example, given array S = {-1 2 1 -4}, and target = 1.
 *
 *         The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

#define ABS(x) ((x)>0?(x):-(x))
int cmp(const void *a,const void *b) {
    return *(int*)a-*(int*)b;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    int i=0,j,k;
    long long res=target>=0?INT_MIN:INT_MAX;
    qsort(nums,numsSize,sizeof(int),cmp);
    if(nums[0]+nums[1]+nums[2]>target)
        return nums[0]+nums[1]+nums[2];
    if(nums[numsSize-1]+nums[numsSize-2]+nums[numsSize-3]<target)
        return nums[numsSize-1]+nums[numsSize-2]+nums[numsSize-3];
    while(nums[i]+nums[i+1]+nums[i+2]<target) {
        j=i+1;k=numsSize-1;
        while(j<k) {
            if(nums[i]+nums[j]+nums[k]==target)
                return target;
            else if(nums[i]+nums[j]+nums[k]<target) {
                if(target-nums[i]-nums[j]-nums[k]<ABS(target-res))
                    res=nums[i]+nums[j]+nums[k];
                do{++j;}while(nums[j-1]==nums[j]);
            } else {
                if(nums[i]+nums[j]+nums[k]-target<ABS(target-res))
                    res=nums[i]+nums[j]+nums[k];
                do{--k;}while(nums[k]==nums[k+1]);
            }
        }
        do{++i;}while(nums[i-1]==nums[i]);
    }
    if(nums[i]+nums[i+1]+nums[i+2]-target<ABS(target-res))
        res=nums[i]+nums[i+1]+nums[i+2];
    return (int)res;
}


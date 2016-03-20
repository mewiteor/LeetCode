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
 * Given a sorted array of integers, find the starting and ending
 * position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 */

int* lower_bound(int* nums,int size,int val) {
    int step,*t;
    while(size) {
        step=size>>1;
        t=nums+step;
        if(*t>=val)
            size=step;
        else {
            nums=t+1;
            size-=step+1;
        }
    }
    return nums;
}
int* upper_bound(int* nums,int size,int val) {
    int step,*t;
    while(size) {
        step=size>>1;
        t=nums+step;
        if(*t>val)
            size=step;
        else {
            nums=t+1;
            size-=step+1;
        } 
    }
    return nums;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    static int r[2];
    int st=lower_bound(nums,numsSize,target)-nums,ed;
    *returnSize=2;
    r[0]=r[1]=-1;
    if(st>=numsSize||nums[st]!=target)return r;
    r[0]=st;
    r[1]=upper_bound(nums+st+1,numsSize-st-1,target)-nums-1;
    return r;
}

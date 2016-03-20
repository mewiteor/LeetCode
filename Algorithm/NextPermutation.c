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
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the
 * lowest possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column
 * and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */

void swap(int *a,int *b) {
    int t=*a;
    *a=*b;
    *b=t;
}

void reverse(int* nums, int numsSize) {
    int *l,*r;
    l=nums,r=nums+numsSize-1;
    while(l<r)
        swap(l++,r--);
}

int* lower_bound(int* start,int* end,int target) {
    int* t;
    while(start<end) {
        t=start+((end-start)>>1);
        if(*t>target)
            start=t+1;
        else
            end=t;
    }
    return start;
}

void nextPermutation(int* nums, int numsSize) {
    int i=numsSize-2;
    while(i>=0&&nums[i]>=nums[i+1])
        --i;
    if(i>=0)
        swap(nums+i,lower_bound(nums+i+1,nums+numsSize,nums[i])-1);
    reverse(nums+i+1,numsSize-i-1);
}

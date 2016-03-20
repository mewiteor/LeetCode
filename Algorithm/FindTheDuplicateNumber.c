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
 * Given an array nums containing n + 1 integers where each integer
 * is between 1 and n (inclusive), prove that at least one duplicate
 * number must exist. Assume that there is only one duplicate number,
 * find the duplicate one.
 *
 * Note:
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n2).
 * There is only one duplicate number in the array, but it could be
 * repeated more than once.
 */

int findDuplicate(int* nums, int numsSize) {
    int i,mid,low=1,high=numsSize-1,count;
    while(low<high) {
        mid=low+high>>1;
        for(i=0,count=0;i<numsSize;++i)
            if(nums[i]<=mid)
                ++count;
        if(count<=mid)
            low=mid+1;
        else
            high=mid;
    }
    return low;
}

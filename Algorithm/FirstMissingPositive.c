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
 * Given an unsorted integer array, find the first missing positive integer.
 *
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 *
 * Your algorithm should run in O(n) time and uses constant space.
 */

int firstMissingPositive(int* nums, int numsSize) {
    int i;
    for(i=0;i<numsSize;++i)
        if(nums[i]<0||nums[i]>numsSize)
            nums[i]=0;
    for(i=0;i<numsSize;++i)
        if(nums[i]&INT_MAX)
            nums[(nums[i]&INT_MAX)-1]|=INT_MIN;
    for(i=0;i<numsSize&&nums[i]&INT_MIN;++i);
    return i+1;
}

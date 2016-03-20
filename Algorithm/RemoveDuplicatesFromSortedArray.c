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
 * Given a sorted array, remove the duplicates in place such that each
 * element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in
 * place with constant memory.
 *
 * For example,
 * Given input array nums = [1,1,2],
 *
 * Your function should return length = 2, with the first two elements
 * of nums being 1 and 2 respectively. It doesn't matter what you
 * leave beyond the new length.
 */

int removeDuplicates(int* nums, int numsSize) {
    if(!nums||numsSize<2)return numsSize;
    else {
        int i,j=1;
        for(i=1;i<numsSize;++i) {
            while(i<numsSize&&nums[i-1]==nums[i])++i;
            if(i<numsSize) nums[j++]=nums[i];
        }
        return j;
    }
}

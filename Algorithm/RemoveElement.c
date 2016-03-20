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
 * Given an array and a value, remove all instances of that value
 * in place and return the new length.
 *
 * Do not allocate extra space for another array, you must do this
 * in place with constant memory.
 *
 * The order of elements can be changed. It doesn't matter what you
 * leave beyond the new length.
 *
 * Example:
 * Given input array nums = [3,2,2,3], val = 3
 *
 * Your function should return length = 2, with the first two elements
 * of nums being 2.
 *
 * Hint:
 *
 * Try two pointers.
 * Did you use the property of "the order of elements can be changed"?
 * What happens when the elements to remove are rare?
 */

int removeElement(int* nums, int numsSize, int val) {
    int i,j=0;
    for(i=0;i<numsSize;++i)
        if(nums[i]!=val)
            nums[j++]=nums[i];
    return j;
}

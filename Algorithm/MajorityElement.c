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
 * Given an array of size n, find the majority element. The majority
 * element is the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority
 * element always exist in the array.
 */

int majorityElement(int* nums, int numsSize) {
    int maj=nums[0],count=0,i;
    for(i=0;i<numsSize;++i) {
        if(!count) {
            maj=nums[i];
            count=1;
        }
        else if(nums[i]==maj)
            ++count;
        else
            --count;
    }
    return maj;
}

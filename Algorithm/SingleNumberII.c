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
 * Given an array of integers, every element appears three times
 * except for one. Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could
 * you implement it without using extra memory?
 */

int singleNumber(int* nums, int numsSize) {
    int p=0,q=0,i,t;
    for(i=0;i<numsSize;++i) {
        q^=p&nums[i];
        p^=nums[i];
        t=~(p&q);
        p&=t;
        q&=t;
    }
    return p;
}

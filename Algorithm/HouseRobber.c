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
 * You are a professional robber planning to rob houses along a street.
 * Each house has a certain amount of money stashed, the only constraint
 * stopping you from robbing each of them is that adjacent houses have
 * security system connected and it will automatically contact the
 * police if two adjacent houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of
 * money of each house, determine the maximum amount of money you can
 * rob tonight without alerting the police.
 */

int rob(int* nums, int numsSize) {
    if(!numsSize)
        return 0;
    else if(1==numsSize)
        return nums[0];
    else {
        int l=nums[0],r=nums[1],i,t;
        if(r<l)
            r=l;
        for(i=2;i<numsSize;++i) {
            t=l+nums[i];
            l=r;
            if(r<t)
                r=t;
        }
        return r;
    }
}

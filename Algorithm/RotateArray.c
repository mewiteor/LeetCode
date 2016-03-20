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
 * Rotate an array of n elements to the right by k steps.
 *
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is
 * rotated to [5,6,7,1,2,3,4].
 *
 * Note:
 * Try to come up as many solutions as you can, there are at least
 * 3 different ways to solve this problem.
 *
 * Hint:
 * Could you do it in-place with O(1) extra space?
 * Related problem: Reverse Words in a String II
 */

void rotate(int* nums, int numsSize, int k) {
    k%=numsSize;
    if(k) {
        int cur,last,i,j,index;
        int gcd=numsSize,b=k;
        while(b) {
            i=gcd;
            gcd=b;
            b=i%b;
        }
        b=numsSize/gcd;
        for(i=0;i<gcd;++i)
            for(j=b,index=i,last=nums[i+numsSize-k];j>0;--j) {
                cur=nums[index];
                nums[index]=last;
                index+=k;
                if(index>=numsSize)
                    index-=numsSize;
                last=cur;
            }
    }
}

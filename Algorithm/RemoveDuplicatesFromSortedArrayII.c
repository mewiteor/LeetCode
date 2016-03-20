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
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 *
 * For example,
 * Given sorted array nums = [1,1,1,2,2,3],
 *
 * Your function should return length = 5, with the first five elements
 * of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave
 * beyond the new length.
 */

int removeDuplicatesNTimes(int *nums, int numsSize, int time) {
    int i=0,j=0,cnt=1;
    if(numsSize<time)
        return numsSize;
    while(++i<numsSize)
        if(nums[j]!=nums[i]) {
            nums[++j]=nums[i];
            cnt=1;
        } else if(cnt<time) {
            nums[++j]=nums[i];
            ++cnt;
        }
    return ++j;
}

int removeDuplicates(int* nums, int numsSize) {
    return removeDuplicatesNTimes(nums,numsSize,2);
}

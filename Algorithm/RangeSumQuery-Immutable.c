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
 * Given an integer array nums, find the sum of the elements between
 * indices i and j (i ≤ j), inclusive.
 *
 * Example:
 * Given nums = [-2, 0, 3, -5, 2, -1]
 *
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * Note:
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 */

struct NumArray {
    int *sums;
    size_t size;
};

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) {
    struct NumArray * numArray;
    size_t i;
    numArray=(struct NumArray*)malloc(sizeof(struct NumArray));
    numArray->size=numsSize+1;
    numArray->sums=(int*)malloc(numArray->size*sizeof(int));
    
    numArray->sums[0]=0;
    for(i=0;i<numsSize;++i)
        numArray->sums[i+1]=numArray->sums[i]+nums[i];
    return numArray;
}

int sumRange(struct NumArray* numArray, int i, int j) {
	return numArray->sums[j+1]-numArray->sums[i];
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) {
    if(numArray) {
        if(numArray->sums)
            free(numArray->sums);
        free(numArray);
    }
}

// Your NumArray object will be instantiated and called as such:
// struct NumArray* numArray = NumArrayCreate(nums, numsSize);
// sumRange(numArray, 0, 1);
// sumRange(numArray, 1, 2);
// NumArrayFree(numArray);

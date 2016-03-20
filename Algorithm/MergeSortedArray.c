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
 * Given two sorted integer arrays nums1 and nums2, merge nums2
 * into nums1 as one sorted array.
 *
 * Note:
 * You may assume that nums1 has enough space (size that is greater
 * or equal to m + n) to hold additional elements from nums2.
 * The number of elements initialized in nums1 and nums2 are m and n respectively.
 */

void merge(int* nums1, int m, int* nums2, int n) {
    int i=m+n;
    while(m&&n) {
        if(nums1[m-1]>nums2[n-1])
            nums1[--i]=nums1[--m];
        else
            nums1[--i]=nums2[--n];
    }
    while(n)
        nums1[--i]=nums2[--n];
}

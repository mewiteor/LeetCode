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
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays.
 * The overall run time complexity should be O(log (m+n)).
 */

int findKth(int* nums1, int nums1Size, int* nums2, int nums2Size, int k) {
    if(nums1Size>nums2Size)
        return findKth(nums2, nums2Size, nums1, nums1Size, k);
    if(!nums1Size)
        return nums2[k-1];
    if(1==k)
        return nums1[0]<nums2[0]?nums1[0]:nums2[0];
    else {
        int pa=nums1Size<k>>1?nums1Size:k>>1,pb=k-pa;
        if(nums1[pa-1]<nums2[pb-1])
            return findKth(nums1+pa, nums1Size-pa, nums2, nums2Size, k-pa);
        else if(nums1[pa-1]>nums2[pb-1])
            return findKth(nums1, nums1Size, nums2+pb, nums2Size-pb, k-pb);
        else
            return nums1[pa-1];
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int k=nums1Size+nums2Size,oe=k&1;
    k>>=1;
    if(oe)
        return findKth(nums1, nums1Size, nums2, nums2Size, k+1);
    else
        return (findKth(nums1, nums1Size, nums2, nums2Size, k)+findKth(nums1, nums1Size, nums2, nums2Size, k+1))/2.0;
}

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
 * You are a product manager and currently leading a team to develop
 * a new product. Unfortunately, the latest version of your product
 * fails the quality check. Since each version is developed based on
 * the previous version, all the versions after a bad version are also bad.
 *
 * Suppose you have n versions [1, 2, ..., n] and you want to find out
 * the first bad one, which causes all the following ones to be bad.
 *
 * You are given an API bool isBadVersion(version) which will return
 * whether version is bad. Implement a function to find the first bad
 * version. You should minimize the number of calls to the API.
 */


// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    long long left=1,right=n+1LL,mid;
    while(left<right) {
        mid=(left+right)>>1;
        if(isBadVersion(mid))
            right=mid;
        else
            left=mid+1;
    }
    return (int)left;
}

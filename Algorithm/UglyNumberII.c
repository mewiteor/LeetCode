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
 * Write a program to find the n-th ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include
 * 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence
 * of the first 10 ugly numbers.
 *
 * Note that 1 is typically treated as an ugly number.
 *
 * Hint:
 *
 * The naive approach is to call isUgly for every number until you reach
 * the nth one. Most numbers are not ugly. Try to focus your effort on
 * generating only the ugly ones.
 *
 * An ugly number must be multiplied by either 2, 3, or 5 from a smaller
 * ugly number.
 *
 * The key is how to maintain the order of the ugly numbers. Try a similar
 * approach of merging from three sorted lists: L1, L2, and L3.
 *
 * Assume you have Uk, the kth ugly number. Then Uk+1 must be
 * Min(L1 * 2, L2 * 3, L3 * 5).
 */

int nthUglyNumber(int n) {
    int *uglyNumbers=(int*)malloc(n*sizeof(int));
    int ps[]={2,3,5},fs[]={2,3,5},is[3]={0};
    int i,min,j;
    
    uglyNumbers[0]=1;
    for(i=1;i<n;++i) {
        min=fs[0];
        for(j=1;j<3;++j)
            if(fs[j]<min)
                min=fs[j];
        uglyNumbers[i]=min;
        for(j=0;j<3;++j)
            if(fs[j]==min)
                fs[j]=ps[j]*uglyNumbers[++is[j]];
    }
    i=uglyNumbers[n-1];
    free(uglyNumbers);
    return i;
}

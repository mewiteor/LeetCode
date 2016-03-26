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
 * Write a program to find the nth super ugly number.
 *
 * Super ugly numbers are positive numbers whose all prime factors
 * are in the given prime list primes of size k. For example,
 * [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of
 * the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.
 *
 * Note:
 * (1) 1 is a super ugly number for any given primes.
 * (2) The given numbers in primes are in ascending order.
 * (3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
 */

int nthSuperUglyNumber(int n, int* primes, int primesSize) {
    int *uglyNumbers=(int*)malloc(n*sizeof(int));
    int *fs=(int*)malloc(primesSize*sizeof(int)),*is=(int*)calloc(primesSize,sizeof(int));
    int i,min,j;
    
    memcpy(fs,primes,primesSize*sizeof(int));
    uglyNumbers[0]=1;
    for(i=1;i<n;++i) {
        min=fs[0];
        for(j=1;j<primesSize;++j)
            if(fs[j]<min)
                min=fs[j];
        uglyNumbers[i]=min;
        for(j=0;j<primesSize;++j)
            if(fs[j]==min)
                fs[j]=primes[j]*uglyNumbers[++is[j]];
    }
    i=uglyNumbers[n-1];
    free(uglyNumbers);
    free(fs);
    free(is);
    return i;
}

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
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 *
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.
 *
 * Note: Given n will be between 1 and 9 inclusive.
 */

unsigned short fast_log2(double n){
	return ( *( (unsigned long long*)&n ) >> 52 ) - 1023;
}
unsigned short get_n(unsigned short c,int n){
    while(n--)c&=(c-1);
    return fast_log2(c&~(c-1));
}
char* getPermutation(int n, int k) {
    static const int ns[]={1,2,6,24,120,720,5040,40320,362880};
    char *ret=(char*)malloc((n+1)*sizeof(char));
    int i,j;
    unsigned short c=(1<<n)-1,t;
    ret[n]=0;
    k=(k-1)%ns[n-1];
    for(i=n-1,j=0;i>0;--i,++j) {
        t=get_n(c,k/ns[i-1]);
        ret[j]=t+'1';
        c&=~(1<<t);
        k%=ns[i-1];
    }
	ret[n-1]=fast_log2(c)+'1';
    return ret;
}

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
 * Given two integers n and k, return all possible combinations of
 * k numbers out of 1 ... n.
 * 
 * For example,
 * If n = 4 and k = 2, a solution is:
 * 
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 */

void push(int n,int **ret,int *i,int *dat,int maxLen,int len) {
    if(len==maxLen)
        memcpy(ret[(*i)++],dat,sizeof(int)*len);
    else
        for(dat[len]=!len?1:dat[len-1]+1;dat[len]<=n-(maxLen-len-1);++dat[len])
            push(n,ret,i,dat,maxLen,len+1);
}

/*
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combine(int n, int k, int** columnSizes, int* returnSize) {
    int **ret,i,*dat;
    int p=1,q=1;
    if(n<k||n<=0||k<=0) {
        *returnSize=0;
        *columnSizes=(int*)malloc(0);
        return (int**)malloc(0);
    }
    for(i=0;i<k;++i) {
        p*=n-i;
        q*=k-i;
    }
    *returnSize=p/=q;
    ret=(int**)malloc(sizeof(int*)*p);
    for(i=0;i<p;++i)
        ret[i]=(int*)malloc(sizeof(int)*k);
    *columnSizes=(int*)malloc(p*sizeof(int));
    for(i=0;i<p;++i)
        (*columnSizes)[i]=k;
    dat=(int*)malloc(sizeof(int)*k);
    i=0;
    push(n,ret,&i,dat,k,0);
    return ret;
}

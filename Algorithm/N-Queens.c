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
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 *
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 *
 * [
 *  [".Q..",  // Solution 1
 *   "...Q",
 *   "Q...",
 *   "..Q."],
 *
 *  ["..Q.",  // Solution 2
 *   "Q...",
 *   "...Q",
 *   ".Q.."]
 * ]
 */

#define MAX 31

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char*** solveNQueens(int n, int* returnSize) {
    char ***res;

    int resTable[MAX]={0},
        rowTable[MAX]={0},
        ldTable[MAX]={0},
        rdTable[MAX]={0},
        bfTable[MAX]={0};

    int top;
    int odd=(n&1)+2;
    int bitfield;
    int p;
    int mask=(1<<n)-1;
    int nrow;
    
    res=(char***)malloc(0);
    if(n>=MAX)return res;
    if(!returnSize)return res;
    *returnSize=0;
    if(n<4)
        switch(n) {
            case 1: res = (char***)realloc(res,sizeof(char**));
                    res[0]=(char**)malloc(sizeof(char*));
                    res[0][0]=(char*)malloc(sizeof(char)*2);
                    *(uint16_t*)res[0][0]='Q';
                    *returnSize=1;
            default: return res;
        }
    while(--odd) {
        bitfield=(1<<(n>>1))+odd-2;
        top=nrow=odd-1;
        rowTable[0]=ldTable[0]=rdTable[0]=0;
        if(1==odd)
            resTable[0]=0;
        else {
            rowTable[1]=resTable[0]=bitfield;
            ldTable[1]=bitfield<<1;
            rdTable[1]=bitfield>>1;
            bitfield=(bitfield-1)>>1;
        }
        for(;;) {
            if(!bitfield) {
                if(!top)
                    break;
                bitfield=bfTable[--top];
                --nrow;
                continue;
            }
            p=bitfield&-bitfield;
            bitfield-=p;
            resTable[nrow]=p;
            if(nrow<n-1) {
                int t=nrow++;
                rowTable[nrow]=rowTable[t]|p;
                ldTable[nrow]=(ldTable[t]|p)<<1;
                rdTable[nrow]=(rdTable[t]|p)>>1;
                bfTable[top++]=bitfield;
                bitfield=mask&~(rowTable[nrow]|ldTable[nrow]|rdTable[nrow]);
            } else {
                int i,j,k;
                res=(char***)realloc(res,(*returnSize+2)*sizeof(char**));
                for(k=0;k<2;++k,++*returnSize) {
                    res[*returnSize]=(char**)malloc(sizeof(char*)*n);
                    for(i=0;i<n;++i) {
                        int t=resTable[i];
                        res[*returnSize][i]=(char*)malloc(sizeof(char)*(n+1));
                        if(k)
                            for(j=n;j--;t>>=1)
                                res[*returnSize][i][j]=t&1?'Q':'.';
                        else
                            for(j=0;j<n;++j,t>>=1)
                                res[*returnSize][i][j]=t&1?'Q':'.';
                        res[*returnSize][i][n]=0;
                    }
                }
                bitfield=bfTable[--top];
                --nrow;
            }
        }
    }
    return res;
}

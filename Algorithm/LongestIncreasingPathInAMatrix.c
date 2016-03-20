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
 * Given an integer matrix, find the length of the longest increasing path.
 * 
 * From each cell, you can either move to four directions: left, right, up or down.
 * You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
 * 
 * Example 1:
 * 
 * nums = [
 *   [9,9,4],
 *   [6,6,8],
 *   [2,1,1]
 * ]
 * Return 4
 * The longest increasing path is [1, 2, 6, 9].
 * 
 * Example 2:
 * 
 * nums = [
 *   [3,4,5],
 *   [3,2,6],
 *   [2,2,1]
 * ]
 * Return 4
 * The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
 */

void check(int** matrix, int matrixRowSize, int matrixColSize, int i, int j, int** mem) {
    int max=1,tmp;
    if(i>0&&matrix[i][j]<matrix[i-1][j]) {
        if(!mem[i-1][j])
            check(matrix, matrixRowSize, matrixColSize, i-1, j, mem);
        tmp=mem[i-1][j]+1;
        if(tmp>max)
            max=tmp;
    }
    if(j>0&&matrix[i][j]<matrix[i][j-1]) {
        if(!mem[i][j-1])
            check(matrix, matrixRowSize, matrixColSize, i, j-1, mem);
        tmp=mem[i][j-1]+1;
        if(tmp>max)
            max=tmp;
    }
    if(i<matrixRowSize-1&&matrix[i][j]<matrix[i+1][j]) {
        if(!mem[i+1][j])
            check(matrix, matrixRowSize, matrixColSize, i+1, j, mem);
        tmp=mem[i+1][j]+1;
        if(tmp>max)
            max=tmp;
    }
    if(j<matrixColSize-1&&matrix[i][j]<matrix[i][j+1]) {
        if(!mem[i][j+1])
            check(matrix, matrixRowSize, matrixColSize, i, j+1, mem);
        tmp=mem[i][j+1]+1;
        if(tmp>max)
            max=tmp;
    }
    mem[i][j]=max;
}
int longestIncreasingPath(int** matrix, int matrixRowSize, int matrixColSize) {
    int** mem,i,j,max=1;
    if(matrixRowSize<=0&&matrixColSize<=0)
        return 0;
    mem=(int**)malloc(sizeof(int*)*matrixRowSize);
    for(i=0;i<matrixRowSize;++i)
        mem[i]=(int*)calloc(matrixColSize,sizeof(int));
    for(i=0;i<matrixRowSize;++i)
        for(j=0;j<matrixColSize;++j) {
            if(!mem[i][j])
                check(matrix, matrixRowSize, matrixColSize, i, j, mem);
            if(max<mem[i][j])
                max=mem[i][j];
        }
    for(i=0;i<matrixRowSize;++i)
        free(mem[i]);
    free(mem);
    return max;
}

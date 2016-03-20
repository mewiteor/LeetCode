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
 * Given a matrix of m x n elements (m rows, n columns), return all
 * elements of the matrix in spiral order.
 *
 * For example,
 * Given the following matrix:
 *
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * You should return [1,2,3,6,9,8,7,4,5].
 */

/*
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int *ret=(int*)malloc(matrixRowSize*matrixColSize*sizeof(int));
    int i=0,j,k,r,c,t=(matrixRowSize<matrixColSize?matrixRowSize:matrixColSize)>>1;
    for(j=0,r=matrixRowSize-1,c=matrixColSize-1;j<t;++j,r-=2,c-=2) {
        for(k=0;k<c;++k) ret[i++]=matrix[j][j+k];
        for(k=0;k<r;++k) ret[i++]=matrix[j+k][j+c];
        for(k=0;k<c;++k) ret[i++]=matrix[j+r][j+c-k];
        for(k=0;k<r;++k) ret[i++]=matrix[j+r-k][j];
    }
    if(i<matrixRowSize*matrixColSize) {
        if(matrixRowSize>matrixColSize)
            for(k=0;k<=r;++k) ret[i++]=matrix[t+k][t+c];
        else
            for(k=0;k<=c;++k) ret[i++]=matrix[t][t+k];
    }
    return ret;
}

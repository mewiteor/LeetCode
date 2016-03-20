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
 * Given numRows, generate the first numRows of Pascal's triangle.
 * 
 * For example, given numRows = 5,
 * Return
 * 
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 */

/*
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes, int* returnSize) {
    int i,j,**r;
    if(!numRows){*columnSizes=NULL;*returnSize=0;return NULL;}
    *returnSize=numRows;
    r=(int**)malloc(numRows*sizeof(int*));
    *columnSizes=(int*)malloc(numRows*sizeof(int));
    for(i=0;i<numRows;++i) {
        r[i]=(int*)malloc((i+1)*sizeof(int));
        (*columnSizes)[i]=i+1;
        r[i][0]=1;
        r[i][i]=1;
        for(j=1;j<i;++j)
            r[i][j]=r[i-1][j-1]+r[i-1][j];
    }
    return r;
}

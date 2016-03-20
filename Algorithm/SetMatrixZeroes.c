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
 * Given a m x n matrix, if an element is 0, set its entire row and
 * column to 0. Do it in place.
 *
 * Follow up:
 * Did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 */

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int str=0,stc=matrixColSize,j,i,k;
    if(matrixRowSize<2&&matrixColSize<2)
        return;
    while(str<matrixRowSize) {
        for(stc=0;stc<matrixColSize&&matrix[str][stc];++stc);
        if(stc==matrixColSize)
            ++str;
        else
            break;
    }
    if(str==matrixRowSize)
        return;
    for(i=str+1;i<matrixRowSize;++i) {
        for(j=0,k=0;j<matrixColSize;++j)
            if(!matrix[i][j]) {
                matrix[str][j]=0;
                ++k;
            }
        if(k)
            memset(matrix[i],0,sizeof(int)*matrixColSize);
    }
    for(i=0;i<matrixColSize;++i)
        if(!matrix[str][i])
            for(j=0;j<matrixRowSize;++j)
                matrix[j][i]=0;
    memset(matrix[str],0,sizeof(int)*matrixColSize);
}

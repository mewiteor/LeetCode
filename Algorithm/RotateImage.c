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
 * You are given an n x n 2D matrix representing an image.
 *
 * Rotate the image by 90 degrees (clockwise).
 *
 * Follow up:
 * Could you do this in-place?
 */

void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    int i,j,r=0,t,size=matrixRowSize-2;
    for(i=matrixRowSize>>1;i>0;--i,size-=2,++r)
        for(j=size;j>=0;--j) {
            t=matrix[r][r+j];
            matrix[r][r+j]=matrix[r+size-j+1][r];
            matrix[r+size-j+1][r]=matrix[r+size+1][r+size-j+1];
            matrix[r+size+1][r+size-j+1]=matrix[r+j][r+size+1];
            matrix[r+j][r+size+1]=t;
        }
}

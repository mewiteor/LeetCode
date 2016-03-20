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
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * For example,
 * 
 * Consider the following matrix:
 * 
 * [
 *   [1,   4,  7, 11, 15],
 *   [2,   5,  8, 12, 19],
 *   [3,   6,  9, 16, 22],
 *   [10, 13, 14, 17, 24],
 *   [18, 21, 23, 26, 30]
 * ]
 * Given target = 5, return true.
 * 
 * Given target = 20, return false.
 */

bool sub(int** matrix,int startX,int startY,int width,int height,int target) {
    if(!width||!height)
        return false;
    else if(width==1&&height==1)
        return target==matrix[startX][startY];
    else if(width==1) {
        int t,h;
        while(height) {
            h=height>>1;
            t=startX+h;
            if(matrix[t][startY]==target)
                return true;
            else if(matrix[t][startY]<target) {
                startX=t+1;
                height-=h+1;
            }
            else
                height=h;
        }
        return false;
    } else if(height==1) {
        int t,w;
        while(width) {
            w=width>>1;
            t=startY+w;
            if(matrix[startX][t]==target)
                return true;
            else if(matrix[startX][t]<target) {
                startY=t+1;
                width-=w+1;
            }
            else width=w;
        }
        return false;
    } else {
        int w=width>>1,h=height>>1;
        int r=matrix[startX+h][startY+w];
        if(r==target)
            return r;
        else if(r<target)
            return  sub(matrix,startX+h+1,startY,w+1,height-h-1,target)||
                    sub(matrix,startX,startY+w+1,width-w-1,h+1,target)||
                    sub(matrix,startX+h+1,startY+w+1,width-w-1,height-h-1,target);
        else
            return  sub(matrix,startX+h,startY,w,height-h,target)||
                    sub(matrix,startX,startY+w,width-w,h,target)||
                    sub(matrix,startX,startY,w,h,target);
    }
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    return sub(matrix,0,0,matrixColSize, matrixRowSize, target);
}

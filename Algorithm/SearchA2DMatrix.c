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
 * Write an efficient algorithm that searches for a value in an
 * m x n matrix. This matrix has the following properties:
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * For example,
 *
 * Consider the following matrix:
 *
 * [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * Given target = 3, return true.
 */

#define MI(x) (matrix[(x)/matrixColSize][(x)%matrixColSize])

int lower_bound(int** matrix, int matrixRowSize, int matrixColSize, int begin, int end, int target) {
    int it,step;
    
    while(end>begin) {
        step = end-begin>>1;
        it = begin+step;
        if(MI(it)<target)
            begin=it+1;
        else
            end=begin+step;
    }
    return begin;
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int begin=lower_bound(matrix,matrixRowSize,matrixColSize,0,matrixRowSize*matrixColSize,target);
    return begin!=matrixRowSize*matrixColSize&&target==MI(begin);
}

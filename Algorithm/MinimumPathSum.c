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
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 */

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int i,j,min,max;
    int *r=(int*)malloc(min*sizeof(int));
    int rl=gridRowSize<gridColSize;
    
    if(rl) {
        min=gridRowSize;
        max=gridColSize;
    } else {
        min=gridColSize;
        max=gridRowSize;
    }
    
    r[min-1]=grid[gridRowSize-1][gridColSize-1];
    
    i=min-1;
    while(i--)
        r[i]=(rl?grid[i][max-1]:grid[max-1][i])+r[i+1];
        
    i=max-1;
    while(i--) {
        j=min-1;
        r[j]+=rl?grid[j][i]:grid[i][j];
        while(j--)
            r[j]=(r[j+1]<r[j]?r[j+1]:r[j])+(rl?grid[j][i]:grid[i][j]);
    }
    
    i=r[0];
    free(r);
    return i;
}

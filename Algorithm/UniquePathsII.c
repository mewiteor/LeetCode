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
 * Follow up for "Unique Paths":
 *
 * Now consider if some obstacles are added to the grids.
 * How many unique paths would there be?
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 *
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 *
 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 * The total number of unique paths is 2.
 *
 * Note: m and n will be at most 100.
 */

void sub(int **arr,int x,int y,int w,int h) {
    int r=0,b=0;
    if (x+1<w&&1!=arr[y][x+1]) {
        if (!arr[y][x+1])
            sub(arr,x+1,y,w,h);
        r=~arr[y][x+1];
    }
    if (y+1<h&&1!=arr[y+1][x]) {
        if (!arr[y+1][x])
            sub(arr,x,y+1,w,h);
        b=~arr[y+1][x];
    }
    arr[y][x]=~(r+b);
}

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    if(!obstacleGrid||!obstacleGridRowSize||!obstacleGridColSize)
        return 0;
    else if (1==obstacleGrid[obstacleGridRowSize-1][obstacleGridColSize-1]||
        1==obstacleGrid[0][0])
        return 0;
    else if (1==obstacleGridRowSize&&1==obstacleGridColSize)
        return 1;
    obstacleGrid[obstacleGridRowSize-1][obstacleGridColSize-1]=~1;
    sub(obstacleGrid,0,0,obstacleGridColSize,obstacleGridRowSize);
    return ~obstacleGrid[0][0];
}
